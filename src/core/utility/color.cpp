//
// Created by Kimera Royal on 22/01/2024.
//

#include "color.h"

namespace bombengine
{
    const glm::vec4 Color::c_black = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    const glm::vec4 Color::c_red = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    const glm::vec4 Color::c_green = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
    const glm::vec4 Color::c_blue = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
    const glm::vec4 Color::c_yellow = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
    const glm::vec4 Color::c_purple = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
    const glm::vec4 Color::c_cyan = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
    const glm::vec4 Color::c_white = glm::vec4(1.0f);

    glm::vec4 Color::ConvertColorFormat(const SDL_Color _color)
    {
        return glm::vec4(_color.r, _color.g, _color.b, _color.a) / 255.0f;
    }

    SDL_Color Color::ConvertColorFormat(const glm::vec4 _color)
    {
        return SDL_Color(static_cast<Uint8>(_color.r * 255.0f), static_cast<Uint8>(_color.g * 255.0f), static_cast<Uint8>(_color.b * 255.0f), static_cast<Uint8>(_color.a * 255.0f));
    }
} // bombengine