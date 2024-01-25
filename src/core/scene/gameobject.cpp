//
// Created by Kimera Royal on 21/01/2024.
//

#include "gameobject.h"

#include <stdexcept>

#include "component.h"

namespace bombengine
{
    GameObject::GameObject(glm::vec3 _position, glm::quat _rotation, glm::vec3 _scale)
        : m_transform(_position, _rotation, _scale)
    {
    }

    GameObject::GameObject(glm::vec3 _position, glm::vec3 _eulerAngles, glm::vec3 _scale)
        : m_transform(_position, _eulerAngles, _scale)
    {
    }

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

    void GameObject::AddComponent(const std::shared_ptr<Component>& _component)
    {
        _component->SetParent(shared_from_this());
        m_components.push_back(_component);
        _component->Load();
    }

    std::shared_ptr<GameObject> GameObject::Initialize(const glm::vec3 _position, const glm::quat _rotation, const glm::vec3 _scale)
    {
        return std::shared_ptr<GameObject>(new GameObject(_position, _rotation, _scale));
    }

    std::shared_ptr<GameObject> GameObject::Initialize(const glm::vec3 _position, const glm::vec3 _eulerAngles, const glm::vec3 _scale)
    {
        return std::shared_ptr<GameObject>(new GameObject(_position, _eulerAngles, _scale));
    }
} // bombengine