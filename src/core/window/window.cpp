//
// Created by s5311430 on 06/10/2023.
//

#include "window.h"

namespace bombengine
{
    Window::Window(std::shared_ptr<Context> &_context, const Uint32 _flags)
        : m_window(nullptr)
    {
        m_window = SDL_CreateWindow("Title", 10, 10, 100, 100, _flags);
        if(!m_window) { throw std::runtime_error("Could not create SDL Window."); }

        if(!_context) { _context = std::make_shared<Context>(m_window); }
        m_context = _context;
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
    }
} // bombengine