//
// Created by Kimera Royal on 22/01/2024.
//

#pragma once

#include <glm/mat4x4.hpp>

class CameraTarget
{
public:
    virtual ~CameraTarget() = default;

    virtual void Draw(glm::mat4 _viewMatrix, glm::mat4 _projectionMatrix) = 0;
};
