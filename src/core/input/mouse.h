//
// Created by s5311430 on 08/12/2023.
//

#pragma once

#include <glm/vec2.hpp>
#include <SDL2/SDL_events.h>

namespace bombengine
{
    struct MouseData
    {
        static constexpr unsigned int c_mouseButtonCount = 5;

        glm::ivec2 m_position;
        unsigned short m_buttonsDown[c_mouseButtonCount];

        [[nodiscard]] bool IsButtonDown(const unsigned int _button) const { return m_buttonsDown[_button]; }
        [[nodiscard]] bool IsButtonUp(const unsigned int _button) const { return !m_buttonsDown[_button]; }
        [[nodiscard]] bool IsButtonPressed(const unsigned int _button, const MouseData& _last) const { return m_buttonsDown[_button] && !_last.m_buttonsDown[_button]; }
        [[nodiscard]] bool IsButtonUnpressed(const unsigned int _button, const MouseData& _last) const { return !m_buttonsDown[_button] && _last.m_buttonsDown[_button]; }
        [[nodiscard]] bool IsButtonHeld(const unsigned int _button, const MouseData& _last) const { return m_buttonsDown[_button] && _last.m_buttonsDown[_button]; }
        [[nodiscard]] unsigned short GetButtonClicks(const unsigned int _button) const { return m_buttonsDown[_button]; }
    };

    class Mouse
    {
    private:
        MouseData m_localData;
        MouseData m_lastLocalData;

        MouseData m_globalData;
        MouseData m_lastGlobalData;
    public:
        Mouse();

        void Update();
        void PostUpdate();

        void HandleEvents(const SDL_Event& _event);

        [[nodiscard]] bool IsMoving() const { return m_globalData.m_position != m_lastGlobalData.m_position; }
        [[nodiscard]] bool IsStill() const { return m_globalData.m_position == m_lastGlobalData.m_position; }

        [[nodiscard]] glm::ivec2 GetPosition() const { return m_localData.m_position; }

        [[nodiscard]] bool IsButtonDown(const unsigned int _button) const { return m_localData.IsButtonDown(_button); }
        [[nodiscard]] bool IsButtonUp(const unsigned int _button) const { return m_localData.IsButtonUp(_button); }
        [[nodiscard]] bool IsButtonPressed(const unsigned int _button) const { return m_localData.IsButtonPressed(_button, m_lastLocalData); }
        [[nodiscard]] bool IsButtonUnpressed(const unsigned int _button) const { return m_localData.IsButtonUnpressed(_button, m_lastLocalData); }
        [[nodiscard]] bool IsButtonHeld(const unsigned int _button) const { return m_localData.IsButtonHeld(_button, m_lastLocalData); }
        [[nodiscard]] unsigned short GetButtonClicks(const unsigned int _button) const { return m_localData.GetButtonClicks(_button); }

        [[nodiscard]] glm::ivec2 GetGlobalPosition() const { return m_globalData.m_position; }

        [[nodiscard]] bool IsGlobalButtonDown(const unsigned int _button) const { return m_globalData.IsButtonDown(_button); }
        [[nodiscard]] bool IsGlobalButtonUp(const unsigned int _button) const { return m_globalData.IsButtonUp(_button); }
        [[nodiscard]] bool IsGlobalButtonPressed(const unsigned int _button) const { return m_globalData.IsButtonPressed(_button, m_lastGlobalData); }
        [[nodiscard]] bool IsGlobalButtonUnpressed(const unsigned int _button) const { return m_globalData.IsButtonUnpressed(_button, m_lastGlobalData); }
        [[nodiscard]] bool IsGlobalButtonHeld(const unsigned int _button) const { return m_globalData.IsButtonHeld(_button, m_lastGlobalData); }
        [[nodiscard]] unsigned short GetGlobalButtonClicks(const unsigned int _button) const { return m_globalData.GetButtonClicks(_button); }
    };
} // cppengine
