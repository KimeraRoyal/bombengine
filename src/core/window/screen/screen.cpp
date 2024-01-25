//
// Created by Kimera Royal on 24/01/2024.
//

#include "screen.h"

#include <GL/glew.h>

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "rendering/model/vertexarray.h"
#include "rendering/model/primitive/quad.h"
#include "rendering/texture/graphic.h"
#include "rendering/shader/shader.h"

namespace bombengine
{
    const size_t Screen::s_projectionKey = std::hash<std::string>()("in_Projection");
    const size_t Screen::s_modelKey = std::hash<std::string>()("in_Model");

    Screen::Screen(Shader& _vertexShader, Shader& _fragmentShader, const glm::ivec2 _size)
        : m_quad(Quad::Create()),
        m_size(_size),
        m_projectionMatrix(1.0f), m_projectionMatrixDirty(true),
        m_modelMatrix(1.0f), m_modelMatrixDirty(true)
    {
        _vertexShader.Attach(m_program.GetID());
        _fragmentShader.Attach(m_program.GetID());
        m_program.Link();
    }

    void Screen::Draw()
    {
        if(!m_target) { return; }

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_MULTISAMPLE);
        glEnable(GL_CULL_FACE);

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(m_program.GetID());
        m_target->Bind(m_program.GetID(), 0);

        m_program.SetHashedUniform(s_projectionKey, GetProjectionMatrix());
        m_program.SetHashedUniform(s_modelKey, GetModelMatrix());
        m_quad->Draw();

        glDisable(GL_CULL_FACE);
    }

    glm::mat4 Screen::GetProjectionMatrix()
    {
        if(m_projectionMatrixDirty)
        {
            m_projectionMatrix = glm::ortho(0.0f, static_cast<float>(m_size.x), 0.0f, static_cast<float>(m_size.y), 0.0f, 1.0f);

            m_projectionMatrixDirty = false;
        }
        return m_projectionMatrix;
    }

    glm::mat4 Screen::GetModelMatrix()
    {
        if(m_modelMatrixDirty)
        {
            m_modelMatrix = glm::mat4(1.0f);
            m_modelMatrix = glm::translate(m_modelMatrix, glm::vec3(m_size.x, m_size.y, 0.0f) / 2.0f);
            m_modelMatrix = glm::scale(m_modelMatrix, glm::vec3(m_size.x, m_size.y, 1.0f));

            m_modelMatrixDirty = false;
        }
        return m_modelMatrix;
    }

    void Screen::SetTarget(const std::shared_ptr<Graphic>& _target)
    {
        m_target = _target;

        m_projectionMatrixDirty = true;
        m_modelMatrixDirty = true;
    }
} // bombengine