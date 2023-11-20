//
// Created by s5311430 on 16/11/2023.
//

#include "windowmanager.h"

namespace bombengine
{
    std::shared_ptr<Window> WindowManager::CreateWindow(const WindowProperties& _windowProperties)
    {
        std::shared_ptr<Window> window = std::make_shared<Window>(m_context, _windowProperties);
        m_windows.push_back(window);
        return window;
    }
} // bombengine