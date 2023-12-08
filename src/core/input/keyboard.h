//
// Created by s5311430 on 08/12/2023.
//

#pragma once

#include <SDL2/SDL_events.h>

#include "core/utility/bitset.h"

namespace bombengine
{
    struct KeyboardData
    {
        Bitset m_keycodes;
        Bitset m_scancodes;
    };

    class Keyboard
    {
    private:
        KeyboardData m_data;
        KeyboardData m_lastData;
    public:
        void PostUpdate();

        bool HandleEvent(const SDL_Event* _event);

        [[nodiscard]] bool IsKeyDown(const SDL_KeyCode _keyCode) const { return m_data.m_keycodes.GetBitSet(_keyCode); }
        [[nodiscard]] bool IsKeyUp(const SDL_KeyCode _keyCode) const { return !m_data.m_keycodes.GetBitSet(_keyCode); }
        [[nodiscard]] bool IsKeyPressed(const SDL_KeyCode _keyCode) const { return m_data.m_keycodes.GetBitSet(_keyCode) && !m_lastData.m_keycodes.GetBitSet(_keyCode); }
        [[nodiscard]] bool IsKeyUnpressed(const SDL_KeyCode _keyCode) const { return !m_data.m_keycodes.GetBitSet(_keyCode) && m_lastData.m_keycodes.GetBitSet(_keyCode); }
        [[nodiscard]] bool IsKeyHeld(const SDL_KeyCode _keyCode) const { return m_data.m_keycodes.GetBitSet(_keyCode) && m_lastData.m_keycodes.GetBitSet(_keyCode); }

        [[nodiscard]] bool IsScancodeDown(const SDL_Scancode _scancode) const { return m_data.m_scancodes.GetBitSet(_scancode); }
        [[nodiscard]] bool IsScancodeUp(const SDL_Scancode _scancode) const { return !m_data.m_scancodes.GetBitSet(_scancode); }
        [[nodiscard]] bool IsScancodePressed(const SDL_Scancode _scancode) const { return m_data.m_scancodes.GetBitSet(_scancode) && !m_lastData.m_scancodes.GetBitSet(_scancode); }
        [[nodiscard]] bool IsScancodeUnpressed(const SDL_Scancode _scancode) const { return !m_data.m_scancodes.GetBitSet(_scancode) && m_lastData.m_scancodes.GetBitSet(_scancode); }
        [[nodiscard]] bool IsScancodeHeld(const SDL_Scancode _scancode) const { return m_data.m_scancodes.GetBitSet(_scancode) && m_lastData.m_scancodes.GetBitSet(_scancode); }
    };
} // bombengine
