//
// Created by s5311430 on 20/10/2023.
//

#include "texture.h"

#include <stdexcept>

namespace bombengine
{
    Texture::Texture(const unsigned char* _data, const std::string& _name, const glm::ivec2& _size)
        : m_id(0),
        m_name(_name),
        m_size(_size)
    {
        glGenTextures(1, &m_id);
        if(!m_id) { throw std::runtime_error("Could not generate Texture."); }

        glBindTexture(GL_TEXTURE_2D, m_id);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x, m_size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);

        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &m_id);
    }

    void Texture::Bind(const GLuint _programId, const int _index) const
    {
        glActiveTexture(GL_TEXTURE0 + _index);

        glBindTexture(GL_TEXTURE_2D, m_id);
        glUniform1i(glGetUniformLocation(_programId, m_name.data()), _index);

        glActiveTexture(GL_TEXTURE0);
    }

} // bombengine