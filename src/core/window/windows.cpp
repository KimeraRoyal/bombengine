//
// Created by s5311430 on 16/11/2023.
//

#include "windows.h"

namespace bombengine
{
    Windows::Windows()
        : m_displaySize(1)
    {
        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(0, &displayMode);

        m_displaySize = glm::ivec2(displayMode.w, displayMode.h);
    }

    std::shared_ptr<Window> Windows::CreateWindow(const WindowProperties& _windowProperties)
    {
        std::shared_ptr<Window> window = std::make_shared<Window>(m_context, _windowProperties);
        m_windows.push_back(window);
        return window;
    }

    std::shared_ptr<Window> Windows::GetWindow(const int _index)
    {
        if(_index >= m_windows.size()) { return nullptr; }
        return m_windows[_index];
    }

    std::shared_ptr<Windows> Windows::Initialize()
    {
        std::shared_ptr<Windows> windowManager = std::shared_ptr<Windows>(new Windows);
        return windowManager;
    }
} // bombengine