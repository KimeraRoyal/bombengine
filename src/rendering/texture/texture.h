//
// Created by s5311430 on 20/10/2023.
//

#pragma once

#include <string>

#include <GL/glew.h>

#include <glm/ext/vector_int2.hpp>

namespace bombengine
{
    class Texture
    {
    private:
        GLuint m_id;

        std::string m_name;

        glm::ivec2 m_size;
    public:
        Texture(const unsigned char* _data, const std::string& _name, const glm::ivec2& _size);
        ~Texture();

        void Bind(GLuint _programId, int _index) const;
        void Unbind(int _index) const;
    };
} // bombengine
