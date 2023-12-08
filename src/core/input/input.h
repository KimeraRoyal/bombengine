//
// Created by s5311430 on 08/12/2023.
//

#pragma once
#include "keyboard.h"
#include "mouse.h"

namespace bombengine
{
    class Input
    {
    private:
        Mouse m_mouse;
        Keyboard m_keyboard;
    public:
        void Update();
        void PostUpdate();
    };

} // bombengine
