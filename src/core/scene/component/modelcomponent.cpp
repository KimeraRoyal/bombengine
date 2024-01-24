//
// Created by Kimera Royal on 22/01/2024.
//

#include "modelcomponent.h"

namespace bombengine
{
    void ModelComponent::Draw(const glm::mat4& _viewMatrix, const glm::mat4& _projectionMatrix)
    {
        m_material->Bind();
        m_model->Draw(m_material->GetProgram(), _viewMatrix, _projectionMatrix, glm::mat4(1.0f));
    }
} // bombengine