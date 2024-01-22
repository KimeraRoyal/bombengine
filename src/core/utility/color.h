//
// Created by Kimera Royal on 22/01/2024.
//

#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <SDL2/SDL_pixels.h>

namespace bombengine
{
    class Color
    {
    private:
        Color() = default;
    public:
        static const glm::vec4 c_black;
        static const glm::vec4 c_red;
        static const glm::vec4 c_green;
        static const glm::vec4 c_blue;
        static const glm::vec4 c_yellow;
        static const glm::vec4 c_purple;
        static const glm::vec4 c_cyan;
        static const glm::vec4 c_white;

        static glm::vec4 ConvertColorFormat(SDL_Color _color);

        static SDL_Color ConvertColorFormat(glm::vec4 _color);
        static SDL_Color ConvertColorFormat(const glm::vec3 _color) { return ConvertColorFormat(glm::vec4(_color, 1.0f)); }
    };
} // bombengine
