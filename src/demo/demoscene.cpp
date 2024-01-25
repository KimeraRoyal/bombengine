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

#include "core/window/screen/screen.h"
#include "resources/type/screenfile.h"

namespace bombdemo
{
    bool DemoScene::Load()
    {
        const std::shared_ptr<bombengine::Window> window = GetCore()->GetWindows()->GetWindow(0);

        // Model
        const std::shared_ptr<bombengine::Material> material = bombengine::MaterialFile::LoadFromFile(GetResources(), "res/simple.json");
        const std::shared_ptr<bombengine::Model> model = bombengine::ModelFile::LoadFromFile(GetResources(), "res/cube.obj");

        const std::shared_ptr<bombengine::GameObject> gameObject = AddGameObject();
        gameObject->AddComponent(std::make_shared<bombengine::ModelComponent>(model, material));

        // Camera
        const std::shared_ptr<bombengine::GameObject> camera = AddGameObject();
        const std::shared_ptr<bombengine::CameraComponent> cameraComponent = std::make_shared<bombengine::CameraComponent>(bombengine::ProjectionType::Perspective, window->GetSize(), bombengine::Color::c_red);
        camera->AddComponent(cameraComponent);

        // Screen
        window->GetScreenStack()->AddScreen(bombengine::ScreenFile::LoadFromFile(GetResources(), "res/screen.json", window->GetSize()));
        window->GetScreenStack()->SetTarget(cameraComponent->GetRenderTexture(), glm::ivec2(0));

        return true;
    }
} // bombdemo