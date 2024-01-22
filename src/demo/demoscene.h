//
// Created by s5311430 on 21/11/2023.
//

#pragma once

#include "rendering/material/material.h"
#include "rendering/model/model.h"

#include "core/scene/scene.h"

namespace bombdemo
{
    class DemoScene : public bombengine::Scene
    {
    private:
        std::shared_ptr<bombengine::Material> m_material;
        std::shared_ptr<bombengine::Model> m_model;
    public:
        bool Load() override;
    };
} // bombdemo
