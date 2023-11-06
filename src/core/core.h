#pragma once

#include <memory>

#include "resources/resources.h"

namespace bombengine
{
    struct Core
    {
    private:
        bool m_running;

		std::shared_ptr<Resources> m_resources;

        Core();

        bool Update();
        void Draw();

        bool PollEvents();

    public:
        ~Core();

        void Run();

        static std::shared_ptr<Core> Initialize();
    };
}