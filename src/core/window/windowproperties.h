//
// Created by s5311430 on 16/11/2023.
//

#pragma once

#include <memory>
#include <string>

#include <glm/vec2.hpp>

#include "context.h"

namespace bombengine
{
    static constexpr glm::ivec2 c_defaultWindowSize = glm::ivec2(400, 240);

    struct WindowProperties
    {
        std::string m_name;

        glm::ivec2 m_position;
        glm::ivec2 m_size;

        Uint32 m_flags;
    };
}