//
// Created by s5311430 on 08/12/2023.
//

#include "mouse.h"

#include <algorithm>

#include <SDL2/SDL_mouse.h>

namespace bombengine
{
    Mouse::Mouse()
        : m_localData(glm::vec2(0.0f)), m_lastLocalData(glm::vec2(0.0f)),
        m_globalData(glm::vec2(0.0f)), m_lastGlobalData(glm::vec2(0.0f))
    {
        SDL_GetMouseState(&m_localData.m_position.x, &m_localData.m_position.y);
        std::fill_n(m_localData.m_buttonsDown, sizeof(m_localData.m_buttonsDown), 0x0);
        m_lastLocalData = m_localData;

        SDL_GetGlobalMouseState(&m_globalData.m_position.x, &m_globalData.m_position.y);
        std::fill_n(m_globalData.m_buttonsDown, sizeof(m_globalData.m_buttonsDown), 0x0);
        m_lastGlobalData = m_globalData;
    }

    void Mouse::Update()
    {
        const Uint32 mouseState = SDL_GetGlobalMouseState(&m_globalData.m_position.x, &m_globalData.m_position.y);
        for(unsigned int i = 0; i < MouseData::c_mouseButtonCount; i++)
        {
            m_globalData.m_buttonsDown[i] = (mouseState >> i) & 0x1;
        }
    }

    void Mouse::PostUpdate()
    {
        m_lastLocalData = m_localData;
        m_lastGlobalData = m_globalData;
    }

    void Mouse::HandleEvents(const SDL_Event& _event)
    {
        switch(_event.type)
        {
            case SDL_MOUSEBUTTONDOWN:
            {
				m_localData.m_buttonsDown[_event.button.button - 1] = _event.button.clicks;
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
				m_localData.m_buttonsDown[_event.button.button - 1] = 0;
                break;
            }
            case SDL_MOUSEMOTION:
            {
				m_localData.m_position = glm::ivec2(_event.motion.x, _event.motion.y);
                break;
            }
            default:
            {
                break;
            }
        }
    }
} // cppengine