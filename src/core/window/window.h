//
// Created by s5311430 on 06/10/2023.
//

#pragma once

#include "windowproperties.h"

namespace bombengine
{
    class Window
    {
    private:
        SDL_Window* m_window;

        std::shared_ptr<Context> m_context;
    public:
        Window(const WindowProperties& _windowProperties);
        ~Window();
    };

} // bombengine
