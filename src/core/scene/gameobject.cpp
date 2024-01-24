//
// Created by Kimera Royal on 21/01/2024.
//

#include "gameobject.h"

#include <stdexcept>

#include "component.h"

namespace bombengine
{
    void GameObject::Update() const
    {
        for(const std::shared_ptr<Component>& component : m_components)
        {
            component->Update();
        }
    }

    void GameObject::PostUpdate() const
    {
        for(const std::shared_ptr<Component>& component : m_components)
        {
            component->PostUpdate();
        }
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

    void GameObject::AddComponent(const std::shared_ptr<Component>& _component)
    {
        m_components.push_back(_component);
    }
} // bombengine