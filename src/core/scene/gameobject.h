//
// Created by Kimera Royal on 21/01/2024.
//

#pragma once

#include <memory>
#include <vector>

#include "transform.h"

namespace bombengine
{
    class Scene;
    class Component;

    class GameObject : public std::enable_shared_from_this<GameObject>
    {
    private:
        std::weak_ptr<Scene> m_scene;

        Transform m_transform;

        std::vector<std::shared_ptr<Component>> m_components;

        GameObject(glm::vec3 _position, glm::quat _rotation, glm::vec3 _scale);
        GameObject(glm::vec3 _position, glm::vec3 _eulerAngles, glm::vec3 _scale);
    protected:
        friend class Scene;

        void Update() const;
        void PostUpdate() const;

        void SetScene(const std::shared_ptr<Scene>& _scene) { m_scene = _scene; }

        static std::shared_ptr<GameObject> Initialize(glm::vec3 _position = glm::vec3(0.0f), glm::quat _rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f), glm::vec3 _scale = glm::vec3(1.0f));
        static std::shared_ptr<GameObject> Initialize(glm::vec3 _position = glm::vec3(0.0f), glm::vec3 _eulerAngles = glm::vec3(0.0f), glm::vec3 _scale = glm::vec3(1.0f));
    public:
        void AddComponent(const std::shared_ptr<Component>& _component);

        [[nodiscard]] Transform& GetTransform() { return m_transform; }

        [[nodiscard]] std::shared_ptr<Scene> GetScene() const;
    };
} // bombengine
