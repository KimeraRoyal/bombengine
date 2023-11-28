//
// Created by s5311430 on 21/11/2023.
//

#pragma once

#include <rendering/material/material.h>
#include "core/scene/scene.h"

namespace bombdemo
{
    class DemoScene : public bombengine::Scene
    {
    private:
        std::shared_ptr<bombengine::Material> m_material;

    public:
        bool Load() override;
    };
} // bombdemo
