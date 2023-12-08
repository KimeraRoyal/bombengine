//
// Created by s5311430 on 08/12/2023.
//

#include "keyboard.h"

namespace bombengine
{
    void Keyboard::PostUpdate()
    {
        m_lastData = m_data;
    }

    bool Keyboard::HandleEvent(const SDL_Event* _event)
    {
        switch (_event->type)
        {
        case SDL_KEYDOWN:
            {
                m_data.m_keycodes.Set(_event->key.keysym.sym);
                m_data.m_scancodes.Set(_event->key.keysym.scancode);
                break;
            }
        case SDL_KEYUP:
            {
                m_data.m_keycodes.Clear(_event->key.keysym.sym);
                m_data.m_scancodes.Clear(_event->key.keysym.scancode);
                break;
            }
        default:
            {
                break;
            }
        }
        return true;
    }
} // bombengine