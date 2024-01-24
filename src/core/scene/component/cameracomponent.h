//
// Created by Kimera Royal on 22/01/2024.
//

#pragma once

#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <rendering/camera/camera.h>
#include <rendering/texture/framebuffer.h>
#include <SDL2/SDL_stdinc.h>

#include "core/scene/component.h"
#include "core/window/rendersource.h"

#include "rendering/camera/projection/projectiontype.h"

namespace bombengine
{
    class CameraComponent final : public Component, public RenderSource
    {
    private:
        Camera m_camera;

        std::shared_ptr<FrameBuffer> m_renderTexture;
    public:
        explicit CameraComponent(ProjectionType _projection, glm::ivec2 _renderTextureSize, glm::vec3 _clearColor = glm::vec3(0.0f), Uint32 _clearFlags = GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        void Load() override;

        void Render() override;

        [[nodiscard]] std::shared_ptr<FrameBuffer> GetRenderTexture() const { return m_renderTexture; }
    };
} // bombengine
