//
// Created by Kimera Royal on 21/01/2024.
//

#pragma once

#include <memory>
#include <vector>

namespace bombengine
{
    class Scene;
    class Component;

    class GameObject
    {
    private:
        std::weak_ptr<Scene> m_scene;

        std::vector<std::shared_ptr<Component>> m_components;

        GameObject() = default;
    protected:
        friend class Scene;

        void Update();

        void SetScene(const std::shared_ptr<Scene>& _scene) { m_scene = _scene; }

        static std::shared_ptr<GameObject> Initialize();
    public:
        [[nodiscard]] std::shared_ptr<Scene> GetScene() const;
    };
} // bombengine
