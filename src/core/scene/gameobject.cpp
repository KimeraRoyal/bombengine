//
// Created by Kimera Royal on 21/01/2024.
//

#include "gameobject.h"

#include <stdexcept>

namespace bombengine
{
    void GameObject::Update()
    {
    }

    std::shared_ptr<Scene> GameObject::GetScene() const
    {
        std::shared_ptr<Scene> scene = m_scene.lock();
        if(!scene) { throw std::runtime_error("Failed to retrieve pointer to Scene."); }
        return scene;
    }

    std::shared_ptr<GameObject> GameObject::Initialize()
    {
        return std::shared_ptr<GameObject>(new GameObject);
    }
} // bombengine