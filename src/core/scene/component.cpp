//
// Created by Kimera Royal on 21/01/2024.
//

#include "component.h"

#include <stdexcept>

#include "gameobject.h"
#include "scene.h"

namespace bombengine
{
    std::shared_ptr<GameObject> Component::GetParent() const
    {
        std::shared_ptr<GameObject> parent = m_parent.lock();
        if(!parent) { throw std::runtime_error("Failed to retrieve pointer to parent Game Object."); }
        return parent;
    }

    std::shared_ptr<Scene> Component::GetScene() const
    {
        return GetParent()->GetScene();
    }

    std::shared_ptr<Scenes> Component::GetManager() const
    {
        return GetScene()->GetManager();
    }

    std::shared_ptr<BombCore> Component::GetCore() const
    {
        return GetScene()->GetCore();
    }

    std::shared_ptr<Resources> Component::GetResources() const
    {
        return GetScene()->GetResources();
    }
} // bombengine