//
// Created by s5311430 on 20/10/2023.
//

#pragma once

#include <GL/glew.h>

#include <glm/ext/vector_int2.hpp>

namespace bombengine
{
    class RenderBuffer
    {
    private:
        GLuint m_id;

        GLuint m_format;
    public:
        RenderBuffer(GLuint _format, const glm::ivec2& _size);
        ~RenderBuffer();

        [[nodiscard]] GLuint GetID() const { return m_id; }

        [[nodiscard]] GLuint GetFormat() const { return m_format; }
    };

} // bombengine