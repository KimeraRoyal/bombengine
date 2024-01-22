//
// Created by Kimera Royal on 22/01/2024.
//

#include "cameracomponent.h"

#include "core/utility/color.h"
#include "rendering/camera/projection/projectionfactory.h"

namespace bombengine
{
    CameraComponent::CameraComponent(const ProjectionType _projection, const glm::vec3 _clearColor, const Uint32 _clearFlags)
        : m_camera(ProjectionFactory::CreateProjection(_projection), Color::ConvertColorFormat(_clearColor), _clearFlags)
    {
    }
} // bombengine