//
// Created by s5311430 on 21/11/2023.
//

#pragma once

#include <memory>

namespace bombengine
{
    class BombCore;
    class Scenes;
    class Resources;

    class Scene
    {
    private:
        friend class Scenes;

		std::weak_ptr<Scenes> m_manager;

        void SetManager(const std::shared_ptr<Scenes>& _sceneManager) { m_manager = _sceneManager; }
    protected:
        virtual bool Load() { return true; }

        virtual void Update() { }
    public:
        Scene() = default;
        virtual ~Scene() = default;

        [[nodiscard]] std::shared_ptr<Scenes> GetManager() const;
        [[nodiscard]] std::shared_ptr<BombCore> GetCore() const;
        [[nodiscard]] std::shared_ptr<Resources> GetResources() const;
    };
} // bombengine
