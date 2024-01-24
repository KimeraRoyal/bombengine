//
// Created by Kimera Royal on 22/01/2024.
//

#include "cameracomponent.h"

#include <core/core.h>

#include "core/utility/color.h"
#include "rendering/camera/projection/projectionfactory.h"

namespace bombengine
{
    CameraComponent::CameraComponent(const ProjectionType _projection, const glm::ivec2 _renderTextureSize, const glm::vec3 _clearColor, const Uint32 _clearFlags)
        : m_camera(ProjectionFactory::CreateProjection(_projection), glm::vec4(_clearColor, 1.0f), _clearFlags),
        m_renderTexture(std::make_unique<FrameBuffer>(_renderTextureSize, std::vector<std::string> { "in_RenderTexture" }))
    {
        m_renderTexture->AddColorBuffer(GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, GL_LINEAR, GL_CLAMP_TO_EDGE);
    }

    void CameraComponent::PostUpdate()
    {
        m_renderTexture->BindFramebuffer();
        m_camera.Draw(glm::inverse(glm::mat4(1.0f)));
        m_renderTexture->UnbindFramebuffer();
    }
} // bombengine