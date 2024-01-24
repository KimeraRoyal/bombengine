//
// Created by s5311430 on 21/11/2023.
//

#include "scenes.h"

#include <stdexcept>

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

    void Scenes::PostUpdate() const
    {
        for(const auto& scene : m_scenes)
        {
            scene->PostUpdate();
        }
    }

    std::shared_ptr<Scenes> Scenes::Initialize(const std::shared_ptr<BombCore>& _core)
    {
        std::shared_ptr<Scenes> scenes = std::shared_ptr<Scenes>(new Scenes(_core));
        return scenes;
    }

    std::shared_ptr<BombCore> Scenes::GetCore() const
    {
        std::shared_ptr<BombCore> core = m_core.lock();
        if(!core) { throw std::runtime_error("Failed to retrieve pointer to BombEngine Core."); }
        return core;
    }
} // bombengine