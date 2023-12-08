//
// Created by s5311430 on 08/12/2023.
//

#include "input.h"

namespace bombengine
{
    void Input::Update()
    {
        m_mouse.Update();
    }

    void Input::PostUpdate()
    {
        m_mouse.PostUpdate();
        m_keyboard.PostUpdate();
    }
} // bombengine