//
// Created by s5311430 on 20/10/2023.
//

#pragma once

#include <GL/glew.h>

#include <glm/ext/vector_int2.hpp>

namespace bombengine
{
    class ColorBuffer
    {
    private:
        GLint m_internalFormat;
        GLenum m_format;
        GLenum m_type;

        GLint m_filter;
        GLint m_wrap;

        GLuint m_id;
    public:
        ColorBuffer(GLint _internalFormat, GLenum _format, GLenum _type, GLint _filter, GLint _wrap);
        ~ColorBuffer();

        void Generate(GLuint _id, const glm::ivec2& _size);

        [[nodiscard]] GLuint GetID() const { return m_id; }
    };

} // bombengine
