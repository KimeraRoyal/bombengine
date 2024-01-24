//
// Created by s5311430 on 21/11/2023.
//

#pragma once

#include <memory>
#include <vector>

#include "scene.h"

namespace bombengine
{
    class BombCore;

    class Scenes : public std::enable_shared_from_this<Scenes>
    {
    private:
        std::weak_ptr<BombCore> m_core;

        std::vector<std::shared_ptr<Scene>> m_scenes;

		explicit Scenes(const std::shared_ptr<BombCore>& _core);
    public:
        void Update() const;
        void PostUpdate() const;

        template<typename T>
        std::shared_ptr<T> CreateScene()
        {
			static_assert(std::is_base_of_v<Scene, T>);

            std::shared_ptr<T> scene = std::make_shared<T>();
            scene->SetManager(shared_from_this());
            if(!scene->Load()) { return nullptr; }

            m_scenes.push_back(scene);
            return scene;
        }

		static std::shared_ptr<Scenes> Initialize(const std::shared_ptr<BombCore>& _core);

        std::shared_ptr<BombCore> GetCore() const;
    };
} // bombengine
