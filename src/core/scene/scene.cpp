//
// Created by s5311430 on 28/11/2023.
//

#include "scene.h"

#include <core/core.h>

#include "scenes.h"

namespace bombengine
{
    std::shared_ptr<Scenes> Scene::GetManager() const
    {
        std::shared_ptr<Scenes> manager = m_manager.lock();
        if(!manager) { throw std::runtime_error("Failed to retrieve pointer to Scenes."); }
        return manager;
    }

    std::shared_ptr<BombCore> Scene::GetCore() const
    {
        return GetManager()->GetCore();
    }

    std::shared_ptr<Resources> Scene::GetResources() const
    {
        return GetCore()->GetResources();
    }
}
