//
// Created by s5311430 on 28/11/2023.
//

#pragma once

namespace bombengine
{
    enum class ShaderType
    {
        Vertex = GL_VERTEX_SHADER,
        Geometry = GL_GEOMETRY_SHADER,
        Fragment = GL_FRAGMENT_SHADER,
        Compute = GL_COMPUTE_SHADER
    };
}