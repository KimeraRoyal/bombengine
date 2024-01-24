//
// Created by Kimera Royal on 21/01/2024.
//

#pragma once

#include <memory>

namespace bombengine
{
    class BombCore;
    class Scenes;
    class Resources;
    class Scene;
    class GameObject;

    class Component
    {
    private:
        std::weak_ptr<GameObject> m_parent;
    protected:
        friend class GameObject;

        virtual void Load() {}

        virtual void Update() {}
        virtual void PostUpdate() {}

        void SetParent(const std::shared_ptr<GameObject>& _parent) { m_parent = _parent; }
    public:
        Component() = default;
        virtual ~Component() = default;

        [[nodiscard]] std::shared_ptr<GameObject> GetParent() const;
        [[nodiscard]] std::shared_ptr<Scene> GetScene() const;
        [[nodiscard]] std::shared_ptr<Scenes> GetManager() const;
        [[nodiscard]] std::shared_ptr<BombCore> GetCore() const;
        [[nodiscard]] std::shared_ptr<Resources> GetResources() const;
    };
} // bombengine
