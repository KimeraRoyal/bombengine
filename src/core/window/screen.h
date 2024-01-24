//
// Created by Kimera Royal on 24/01/2024.
//

#pragma once

#include <memory>
#include <string>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace bombengine
{
    class FrameBuffer;
}

namespace bombengine
{
    class VertexArray;
    class ShaderProgram;
    class Texture;

    class Screen
    {
    private:
        static const size_t s_projectionKey;
        static const size_t s_modelKey;

        std::shared_ptr<VertexArray> m_quad;
        std::shared_ptr<ShaderProgram> m_program;

        std::shared_ptr<FrameBuffer> m_target;
        glm::ivec4 m_targetRegion;

        glm::mat4 m_projectionMatrix;
        bool m_projectionMatrixDirty;

        glm::mat4 m_modelMatrix;
        bool m_modelMatrixDirty;
    public:
        Screen(const std::shared_ptr<ShaderProgram>& _program, const std::shared_ptr<FrameBuffer>& _target, glm::ivec4 _targetRegion);

        void Draw();

        glm::mat4 GetProjectionMatrix();
        glm::mat4 GetModelMatrix();

        [[nodiscard]] std::shared_ptr<FrameBuffer> GetTarget() const { return m_target; }
        void SetTarget(const std::shared_ptr<FrameBuffer>& _target, glm::ivec4 _targetRegion);
    };
} // bombengine