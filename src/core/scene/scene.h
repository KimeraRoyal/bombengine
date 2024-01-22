//
// Created by s5311430 on 21/11/2023.
//

#pragma once

#include <memory>
#include <vector>

#include "gameobject.h"

namespace bombengine
{
    class BombCore;
    class Scenes;
    class Resources;

    class Scene
    {
    private:
		std::weak_ptr<Scenes> m_manager;

        std::vector<std::shared_ptr<GameObject>> m_gameObjects;
    protected:
        friend class Scenes;

        Scene() = default;

        virtual bool Load() { return true; }

        virtual void Update() { }

        void SetManager(const std::shared_ptr<Scenes>& _sceneManager) { m_manager = _sceneManager; }
    public:
        virtual ~Scene() = default;

        std::shared_ptr<GameObject> AddGameObject();

        [[nodiscard]] std::shared_ptr<Scenes> GetManager() const;
        [[nodiscard]] std::shared_ptr<BombCore> GetCore() const;
        [[nodiscard]] std::shared_ptr<Resources> GetResources() const;
    };
} // bombengine
