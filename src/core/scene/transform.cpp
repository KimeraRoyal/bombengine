//
// Created by Kimera Royal on 25/01/2024.
//

#include "transform.h"

#include <stdexcept>

namespace bombengine
{
    Transform::Transform(glm::vec3 _position, glm::quat _rotation, glm::vec3 _scale)
        : m_parent(nullptr),
        m_position(_position), m_rotation(_rotation), m_scale(_scale),
        m_localModelMatrix(1.0f), m_localModelMatrixDirty(true),
        m_modelMatrix(1.0f), m_modelMatrixDirty(true)
    {
    }

    Transform::Transform(glm::vec3 _position, glm::vec3 _eulerAngles, glm::vec3 _scale)
        : Transform(_position, glm::quat(glm::radians(_eulerAngles)), _scale)
    {
    }

    glm::mat4 Transform::GetLocalModelMatrix() const
    {
        if(m_localModelMatrixDirty)
        {
            m_localModelMatrix = glm::mat4(1.0f);
            m_localModelMatrix = glm::translate(m_localModelMatrix, m_position);
            m_localModelMatrix = m_localModelMatrix * glm::mat4_cast(m_rotation);
            m_localModelMatrix = glm::scale(m_localModelMatrix, m_scale);

            m_localModelMatrixDirty = false;
        }
        return m_localModelMatrix;
    }

    glm::mat4 Transform::GetModelMatrix() const // NOLINT(misc-no-recursion)
    {
        if(m_modelMatrixDirty)
        {
            m_modelMatrix = GetLocalModelMatrix();
            if(m_parent) { m_modelMatrix = m_parent->GetModelMatrix() * m_modelMatrix; }

            m_modelMatrixDirty = false;
        }
        return m_modelMatrix;
    }

    Transform* Transform::GetChild(unsigned int _index) const
    {
        if(m_children.size() <= _index) { return nullptr; }
        return m_children[_index];
    }

    void Transform::SetParent(Transform* _parent)
    {
        if(m_parent) { throw std::runtime_error("Cannot currently reassign transform parent."); } // TODO: Implement this.
        m_parent = _parent;
        if(_parent) { _parent->AddChild(this); }
    }

    void Transform::AddChild(Transform* _child)
    {
        m_children.push_back(_child);
    }

    void Transform::MarkDirty()
    {
        m_localModelMatrixDirty = true;
        m_modelMatrixDirty = true;
    }
} // bombengine