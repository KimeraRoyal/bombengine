//
// Created by Kimera Royal on 22/01/2024.
//

#pragma once

#include "rendering/renderable.h"

#include "rendering/material/material.h"
#include "rendering/model/model.h"

#include "core/scene/component.h"

namespace bombengine
{
    class ModelComponent final : public Component, public Renderable
    {
    private:
        std::shared_ptr<Model> m_model;

        std::shared_ptr<Material> m_material;
    public:
        ModelComponent(const std::shared_ptr<Model>& _model, const std::shared_ptr<Material>& _material)
            : m_model(_model),
            m_material(_material)
        {
        }

        void Draw(const glm::mat4& _viewMatrix, const glm::mat4& _projectionMatrix) override;
    };
} // bombengine
