//
// Created by s5311430 on 06/10/2023.
//

#include "window.h"

namespace bombengine
{
    Window::Window(const WindowProperties& _windowProperties)
        : m_window(nullptr)
    {
        m_window = SDL_CreateWindow(_windowProperties.m_name.c_str(), _windowProperties.m_position.x, _windowProperties.m_position.y, _windowProperties.m_size.x, _windowProperties.m_size.y, _windowProperties.m_flags);
        if(!m_window) { throw std::runtime_error("Could not create SDL Window."); }

        if(!_windowProperties.m_context) { _windowProperties.m_context = std::make_shared<Context>(m_window); }
        m_context = _windowProperties.m_context;
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
    }
} // bombengine