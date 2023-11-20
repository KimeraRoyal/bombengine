//
// Created by s5311430 on 16/11/2023.
//

#pragma once

#include <vector>

#include "window.h"

namespace bombengine
{
    class WindowManager
    {
    private:
        std::vector<std::shared_ptr<Window>> m_windows;

        std::shared_ptr<Context> m_context;
    public:
        std::shared_ptr<Window> CreateWindow(const WindowProperties& _windowProperties);
    };
} // bombengine