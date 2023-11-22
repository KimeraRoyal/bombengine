//
// Created by s5311430 on 21/11/2023.
//

#include "scenes.h"

namespace bombengine
{
    Scenes::Scenes(const std::shared_ptr<BombCore>& _core)
        : m_core(_core)
    { }

    void Scenes::Update() const
    {
        for(const auto& scene : m_scenes)
        {
            scene->Update();
        }
    }

    std::shared_ptr<Scenes> Scenes::Initialize(const std::shared_ptr<BombCore>& _core)
    {
        std::shared_ptr<Scenes> scenes = std::shared_ptr<Scenes>(new Scenes(_core));
        return scenes;
    }
} // bombengine