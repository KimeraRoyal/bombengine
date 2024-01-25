//
// Created by Kimera Royal on 24/01/2024.
//

#pragma once

#include <memory>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "rendering/shader/shaderprogram.h"

namespace bombengine
{
    class VertexArray;
    class Graphic;
    class Shader;

    class Screen
    {
    private:
        static const size_t s_projectionKey;
        static const size_t s_modelKey;

        std::shared_ptr<VertexArray> m_quad;
        ShaderProgram m_program;

        std::shared_ptr<Graphic> m_target;

        glm::ivec2 m_size;

        glm::mat4 m_projectionMatrix;
        bool m_projectionMatrixDirty;

        glm::mat4 m_modelMatrix;
        bool m_modelMatrixDirty;
    public:
        Screen(Shader& _vertexShader, Shader& _fragmentShader, glm::ivec2 _size);

        void Draw();

        glm::mat4 GetProjectionMatrix();
        glm::mat4 GetModelMatrix();

        [[nodiscard]] std::shared_ptr<Graphic> GetTarget() const { return m_target; }
        void SetTarget(const std::shared_ptr<Graphic>& _target);

        [[nodiscard]] glm::ivec2 GetSize() const { return m_size; }
        void SetSize(const glm::ivec2 _size) { m_size = _size; }
    };
} // bombengine
