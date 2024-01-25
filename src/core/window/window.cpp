//
// Created by s5311430 on 06/10/2023.
//

#include "window.h"

#include <stdexcept>
#include <GL/glew.h>

namespace bombengine
{
    Window::Window(std::shared_ptr<Context>& _context, const WindowProperties& _windowProperties)
        : m_window(nullptr),
        m_name(_windowProperties.m_name),
        m_position(_windowProperties.m_position), m_size(_windowProperties.m_size),
        m_flags(_windowProperties.m_flags)
    {
        m_window = SDL_CreateWindow(_windowProperties.m_name.c_str(), _windowProperties.m_position.x, _windowProperties.m_position.y, _windowProperties.m_size.x, _windowProperties.m_size.y, _windowProperties.m_flags);
        if(!m_window) { throw std::runtime_error("Could not create SDL Window."); }

        if(!_context) { _context = std::make_shared<Context>(m_window); }
        m_context = _context;
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
    }

    void Window::Draw() const
    {
        MakeCurrent();

        for(auto& source : m_renderSources)
        {
            source->Render();
        }

        if(m_screen) { m_screen->Draw(); }

        SDL_GL_SwapWindow(m_window);
    }

    void Window::MakeCurrent() const
    {
        SDL_GL_MakeCurrent(m_window, m_context->GetGLContext());
    }

    void Window::AddRenderSource(RenderSource* _renderSource)
    {
		m_renderSources.push_back(_renderSource);
    }

    void Window::RemoveRenderSource(const unsigned int _index)
    {
		m_renderSources.erase(m_renderSources.begin() + _index);
    }

    void Window::RemoveRenderSource(RenderSource* _renderSource)
    {
        m_renderSources.erase(std::remove(m_renderSources.begin(), m_renderSources.end(), _renderSource), m_renderSources.end());
    }
} // bombengine