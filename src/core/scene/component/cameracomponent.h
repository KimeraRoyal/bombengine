//
// Created by Kimera Royal on 22/01/2024.
//

#pragma once

#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <rendering/camera/camera.h>
#include <SDL2/SDL_stdinc.h>

#include "core/scene/component.h"

#include "rendering/camera/projection/projectiontype.h"

namespace bombengine
{
    class CameraComponent : public Component
    {
    private:
        Camera m_camera;
    public:
        CameraComponent(ProjectionType _projection, glm::vec3 _clearColor = glm::vec3(0.0f), Uint32 _clearFlags = GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    };
} // bombengine
