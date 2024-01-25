//
// Created by s5311430 on 21/11/2023.
//

#include "demoscene.h"

#include "core/core.h"

#include "resources/type/modelfile.h"
#include "resources/type/materialfile.h"
#include "resources/type/imagefile.h"

#include "core/scene/component/cameracomponent.h"
#include "core/scene/component/modelcomponent.h"

#include "core/utility/color.h"

namespace bombdemo
{
    bool DemoScene::Load()
    {
        std::shared_ptr<bombengine::Texture> cat;

        /*
         * Model
         */
        {
            const std::shared_ptr<bombengine::MaterialFile> materialFile = GetResources()->GetResource<bombengine::MaterialFile>("res/simple.json");

            bombengine::Shader vertexShader(bombengine::ShaderType::Vertex, materialFile->GetVertexShader()->GetData());
            bombengine::Shader fragmentShader(bombengine::ShaderType::Fragment, materialFile->GetFragmentShader()->GetData());

            const std::shared_ptr<bombengine::ImageFile> textureFile = GetResources()->GetResource<bombengine::ImageFile>("res/cat.png");
            std::vector<std::shared_ptr<bombengine::Texture>> textures;
            cat = std::make_shared<bombengine::Texture>(textureFile->GetData(), "cat", textureFile->GetSize());
            textures.push_back(cat);

            const std::shared_ptr<bombengine::Material> material = std::make_shared<bombengine::Material>(vertexShader, fragmentShader, textures);

            const std::shared_ptr<bombengine::ModelFile> modelFile = GetResources()->GetResource<bombengine::ModelFile>("res/cube.obj");

            const std::shared_ptr<bombengine::Model> model = std::make_shared<bombengine::Model>();
            model->AddMesh(modelFile->GetData());

            const std::shared_ptr<bombengine::GameObject> gameObject = AddGameObject();
            gameObject->AddComponent(std::make_shared<bombengine::ModelComponent>(model, material));
        }

        /*
         * Camera
         */
        {
            const std::shared_ptr<bombengine::TextFile> screenVertexFile = GetResources()->GetResource<bombengine::TextFile>("res/shader/screen/screen.vert");
            const std::shared_ptr<bombengine::TextFile> screenFragmentFile = GetResources()->GetResource<bombengine::TextFile>("res/shader/screen/screen.frag");

            bombengine::Shader vertexShader(bombengine::ShaderType::Vertex, screenVertexFile->GetData());
            bombengine::Shader fragmentShader(bombengine::ShaderType::Fragment, screenFragmentFile->GetData());

            const std::shared_ptr<bombengine::ShaderProgram> screenShader = std::make_unique<bombengine::ShaderProgram>();
            vertexShader.Attach(screenShader->GetID());
            fragmentShader.Attach(screenShader->GetID());
            screenShader->Link();

            const std::shared_ptr<bombengine::Window> window = GetCore()->GetWindows()->GetWindow(0);

            const std::shared_ptr<bombengine::GameObject> camera = AddGameObject();
            const std::shared_ptr<bombengine::CameraComponent> cameraComponent = std::make_shared<bombengine::CameraComponent>(bombengine::ProjectionType::Perspective, window->GetSize(), bombengine::Color::c_red);
            camera->AddComponent(cameraComponent);

            glm::ivec4 targetRegion = glm::ivec4(0, 0, window->GetSize());
            const std::shared_ptr<bombengine::Screen> screen = std::make_unique<bombengine::Screen>(screenShader, cameraComponent->GetRenderTexture(), targetRegion);
            window->SetScreen(screen);
        }

        return true;
    }
} // bombdemo