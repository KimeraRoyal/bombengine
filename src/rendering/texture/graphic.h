//
// Created by Kimera Royal on 24/01/2024.
//

#pragma once

#include <GL/glew.h>

class Graphic
{
public:
    virtual ~Graphic() = default;

    virtual void Bind(GLuint _programId, int _index) = 0;
};
