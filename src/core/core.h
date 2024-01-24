#pragma once

#include <memory>

#include "input/input.h"
#include "resources/resources.h"

#include "window/windows.h"
#include "scene/scenes.h"
#include "utility/time.h"

namespace bombengine
{
    class BombCore : public std::enable_shared_from_this<BombCore>
    {
    private:
        bool m_running;

        Time m_time;
        Input m_input;

		std::shared_ptr<Resources> m_resources;

        std::shared_ptr<Windows> m_windows;
        std::shared_ptr<Scenes> m_scenes;

        BombCore();
        void Load();

        bool Update();
        void PostUpdate();

        bool PollEvents();
    public:
        ~BombCore();

        void GameLoop();

        std::shared_ptr<Resources> GetResources() { return m_resources; }

        std::shared_ptr<Windows> GetWindows() { return m_windows; }
        std::shared_ptr<Scenes> GetScenes() { return m_scenes; }

        [[nodiscard]] bool IsRunning() const { return m_running; }
        void SetRunning(const bool _running) { m_running = _running; }

        static std::shared_ptr<BombCore> Initialize();
    };
}
