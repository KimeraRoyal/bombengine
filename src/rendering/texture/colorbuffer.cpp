//
// Created by s5311430 on 20/10/2023.
//

#include "colorbuffer.h"

#include <stdexcept>

namespace bombengine
{
    ColorBuffer::ColorBuffer(const GLint _internalFormat, const GLenum _format, const GLenum _type, const GLint _filter, const GLint _wrap)
        : m_internalFormat(_internalFormat), m_format(_format), m_type(_type),
        m_filter(_filter), m_wrap(_wrap),
        m_id(0)
    {

    }

    ColorBuffer::~ColorBuffer()
    {
        glDeleteTextures(1, &m_id);
    }

    void ColorBuffer::Generate(const GLuint _id, const glm::ivec2 &_size)
    {
        if(!_id) { throw std::runtime_error("Passed invalid id when attempting to generate Color Buffer."); }
        m_id = _id;

        glBindTexture(GL_TEXTURE_2D, m_id);

        glTexImage2D(GL_TEXTURE_2D, 0, m_internalFormat, _size.x, _size.y, 0, m_format, m_type, nullptr);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_wrap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_wrap);

        glBindTexture(GL_TEXTURE_2D, 0);
    }
} // bombengine