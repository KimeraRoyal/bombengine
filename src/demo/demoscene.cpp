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
        const std::shared_ptr<bombengine::MaterialFile> materialFile = GetResources()->GetResource<bombengine::MaterialFile>("res/simple.json");

        bombengine::Shader vertexShader(bombengine::ShaderType::Vertex, materialFile->GetVertexShader()->GetData());
        bombengine::Shader fragmentShader(bombengine::ShaderType::Fragment, materialFile->GetFragmentShader()->GetData());

        const std::shared_ptr<bombengine::ImageFile> textureFile = GetResources()->GetResource<bombengine::ImageFile>("res/cat.png");
        std::vector<std::shared_ptr<bombengine::Texture>> textures;
        textures.push_back(std::make_shared<bombengine::Texture>(textureFile->GetData(), "cat", textureFile->GetSize()));

        const std::shared_ptr<bombengine::Material> material = std::make_shared<bombengine::Material>(vertexShader, fragmentShader, textures);

        const std::shared_ptr<bombengine::ModelFile> modelFile = GetResources()->GetResource<bombengine::ModelFile>("res/cube.obj");

        const std::shared_ptr<bombengine::Model> model = std::make_shared<bombengine::Model>();
        model->AddMesh(modelFile->GetData());

        const std::shared_ptr<bombengine::GameObject> gameObject = AddGameObject();
        gameObject->AddComponent(std::make_shared<bombengine::ModelComponent>(model, material));

        const std::shared_ptr<bombengine::GameObject> camera = AddGameObject();
        camera->AddComponent(std::make_shared<bombengine::CameraComponent>(bombengine::ProjectionType::Perspective, bombengine::Color::c_red));

        return true;
    }
} // bombdemo