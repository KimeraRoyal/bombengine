//
// Created by s5311430 on 16/11/2023.
//

#include "windows.h"

namespace bombengine
{
    std::shared_ptr<Window> Windows::CreateWindow(const WindowProperties& _windowProperties)
    {
        std::shared_ptr<Window> window = std::make_shared<Window>(m_context, _windowProperties);
        m_windows.push_back(window);
        return window;
    }

    std::shared_ptr<Windows> Windows::Initialize()
    {
        std::shared_ptr<Windows> windowManager = std::shared_ptr<Windows>(new Windows);
        return windowManager;
    }
} // bombengine