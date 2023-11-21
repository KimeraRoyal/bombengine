//
// Created by s5311430 on 21/11/2023.
//

#pragma once

#include <memory>

namespace bombengine
{
    class Scenes;

    class Scene
    {
    private:
        friend class Scenes;

		std::weak_ptr<Scenes> m_sceneManager;

        void SetSceneManager(const std::shared_ptr<Scenes>& _sceneManager) { m_sceneManager = _sceneManager; }
    protected:
        virtual bool Load() { return true; }

        virtual void Update() { }
    public:
        Scene() = default;
        virtual ~Scene() = default;
    };
} // bombengine
