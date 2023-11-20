#pragma once

#include <memory>

#include "resources/resources.h"

#include "window/windowmanager.h"

namespace bombengine
{
    struct Core
    {
    private:
        bool m_running;

		Resources m_resources;

        WindowManager m_windowManager;

        Core();

        bool Update();
        void Draw();

        bool PollEvents();
    public:
        ~Core();

        void Run();

        static std::shared_ptr<Core> Initialize();

        Resources* GetResources() { return &m_resources; }

        WindowManager* GetWindowManager() { return &m_windowManager; }
    };
}