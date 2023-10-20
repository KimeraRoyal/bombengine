//
// Created by s5311430 on 20/10/2023.
//

#include "renderbuffer.h"

#include <stdexcept>

namespace bombengine
{
    RenderBuffer::RenderBuffer(const GLuint _format, const glm::ivec2& _size)
        : m_id(0),
        m_format(_format)
    {
        glGenRenderbuffers(1, &m_id);
        if(!m_id) { throw std::runtime_error("Could not generate Render Buffer."); }

        glNamedRenderbufferStorage(m_id, m_format, _size.x, _size.y);
    }

    RenderBuffer::~RenderBuffer()
    {
        glDeleteRenderbuffers(1, &m_id);
    }
} // bombengine