//
// Created by s5311430 on 20/10/2023.
//

#pragma once

#include <string>

#include <GL/glew.h>

#include <glm/ext/vector_int2.hpp>

#include "graphic.h"

namespace bombengine
{
    class Texture final : public Graphic
    {
    private:
        GLuint m_id;

        glm::ivec2 m_size;
    public:
        Texture(const unsigned char* _data, const glm::ivec2& _size);
        ~Texture() override;

        void Bind(GLuint _programId, int _index) override;
    };
} // bombengine
