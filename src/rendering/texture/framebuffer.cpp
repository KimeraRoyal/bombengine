//
// Created by s5311430 on 20/10/2023.
//

#include "framebuffer.h"

#include <stdexcept>

namespace bombengine
{
    FrameBuffer::FrameBuffer(const glm::ivec2 &_size, const std::vector<std::string> &_textureNames)
        : m_id(0),
        m_renderBuffer(GL_DEPTH24_STENCIL8, _size),
        m_textureNames(_textureNames),
        m_size(_size),
        m_dirty(false)
    {

    }

    FrameBuffer::~FrameBuffer()
    {
        glDeleteFramebuffers(1, &m_id);
    }

    void FrameBuffer::Generate()
    {
        if(!m_dirty) { return; }

        if(!m_id)
		{
			glGenFramebuffers(1, &m_id);
			if(!m_id) { throw std::runtime_error("Could not generate FrameBuffer."); }
		}

        GenerateColorBuffers();
        glNamedFramebufferRenderbuffer(m_id, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_renderBuffer.GetID());

        m_dirty = false;
    }

    void FrameBuffer::GenerateColorBuffers()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, m_id);

        std::vector<GLuint> textureIds = std::vector<GLuint>(m_colorBuffers.size());
        glGenTextures(static_cast<GLsizei>(m_colorBuffers.size()), textureIds.data());

        std::vector<unsigned int> attachments;
        for(auto i = 0; i < m_colorBuffers.size(); i++)
        {
            m_colorBuffers[i].Generate(textureIds[i], m_size);
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, textureIds[i], 0);
            attachments.push_back(GL_COLOR_ATTACHMENT0 + i);
        }
        glNamedFramebufferDrawBuffers(m_id, static_cast<GLsizei>(m_colorBuffers.size()), attachments.data());

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void FrameBuffer::BindFramebuffer()
    {
        Generate();
        glBindFramebuffer(GL_FRAMEBUFFER, m_id);
    }

    void FrameBuffer::UnbindFramebuffer()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void FrameBuffer::Bind(const GLuint _programId, int _index)
    {
        Generate();
        for(auto i = 0; i < m_colorBuffers.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + _index + i);
            glBindTexture(GL_TEXTURE_2D, m_colorBuffers[i].GetID());
            glUniform1i(glGetUniformLocation(_programId, m_textureNames[i].data()), _index + i);
        }
    }

    void FrameBuffer::AddColorBuffer(const GLint _internalFormat, const GLenum _format, const GLenum _type, const GLint _filter, const GLint _wrap)
    {
		m_colorBuffers.emplace_back(_internalFormat, _format, _type, _filter, _wrap);
    }

    void FrameBuffer::AddColorBuffers(const unsigned int _count, const GLint _internalFormat, const GLenum _format, const GLenum _type, const GLint _filter, const GLint _wrap)
    {
		std::vector<ColorBuffer> newBuffers(_count, ColorBuffer(_internalFormat, _format, _type, _filter, _wrap));
		m_colorBuffers.insert(m_colorBuffers.end(), newBuffers.begin(), newBuffers.end());
    }
} // bombengine