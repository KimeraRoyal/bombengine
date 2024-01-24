//
// Created by Kimera Royal on 24/01/2024.
//

#pragma once

#include <memory>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <rendering/model/vertexarray.h>

namespace bombengine
{
    class Model;

    class Quad
    {
    private:
        static constexpr int c_vertexCount = 6;

        static const glm::vec3 c_vertexPositions[c_vertexCount];
        static const glm::vec3 c_vertexNormals[c_vertexCount];
        static const glm::vec2 c_vertexUVs[c_vertexCount];
    public:
        static std::shared_ptr<VertexArray> Create();
    };
} // bombengine
