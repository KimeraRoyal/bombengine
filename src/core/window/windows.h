//
// Created by s5311430 on 16/11/2023.
//

#pragma once

#include <vector>

#include "window.h"

namespace bombengine
{
    class Windows
    {
    private:
        std::vector<std::shared_ptr<Window>> m_windows;

        std::shared_ptr<Context> m_context;

        Windows() = default;
    public:
        std::shared_ptr<Window> CreateWindow(const WindowProperties& _windowProperties);

        static std::shared_ptr<Windows> Initialize();
    };
} // bombengine