//
// Created by Kimera Royal on 24/01/2024.
//

#include "quad.h"

#include <rendering/model/mesh.h>
#include <rendering/model/model.h>
#include <rendering/model/vertex.h>
#include <rendering/model/vertexarray.h>

namespace bombengine
{
    const glm::vec3 Quad::c_vertexPositions[] =
    {
        glm::vec3(-0.5f, 0.5f, 0.0f),
        glm::vec3(-0.5f, -0.5f, 0.0f),
        glm::vec3(0.5f, 0.5f, 0.0f),
        glm::vec3(-0.5f, -0.5f, 0.0f),
        glm::vec3(0.5f, -0.5f, 0.0f),
        glm::vec3(0.5f, 0.5f, 0.0f)
    };

    const glm::vec3 Quad::c_vertexNormals[] =
    {
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    };

    const glm::vec2 Quad::c_vertexUVs[] =
    {
        glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f)
    };

    std::shared_ptr<VertexArray> Quad::Create()
    {
        std::shared_ptr<VertexBuffer> vertexBuffer = std::make_unique<VertexBuffer>();
        vertexBuffer->AddInterleavedSection(3, offsetof(Vertex, m_position));
        vertexBuffer->AddInterleavedSection(3, offsetof(Vertex, m_normal));
        vertexBuffer->AddInterleavedSection(2, offsetof(Vertex, m_uv));

        for(int i = 0; i < c_vertexCount; i++)
        {
            const Vertex vertex = Vertex(c_vertexPositions[i], c_vertexNormals[i], c_vertexUVs[i]);
            vertexBuffer->AddValue(reinterpret_cast<const float*>(&vertex), 8);
        }

        std::shared_ptr<VertexArray> vertexArray = std::make_unique<VertexArray>();
        vertexArray->AddVertexBuffer(vertexBuffer);
        return vertexArray;
    }
} // bombengine