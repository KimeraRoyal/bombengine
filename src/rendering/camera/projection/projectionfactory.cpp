//
// Created by Kimera Royal on 22/01/2024.
//

#include "projectionfactory.h"

#include "orthographicprojection.h"
#include "perspectiveprojection.h"

namespace bombengine
{
    const float ProjectionFactory::c_defaultNear = 0.001f;
    const float ProjectionFactory::c_defaultFar = 1000.0f;

    std::unordered_map<ProjectionType, std::function<std::unique_ptr<Projection>()>> ProjectionFactory::m_projectionTypes = std::unordered_map<ProjectionType, std::function<std::unique_ptr<Projection>()>>();

    void ProjectionFactory::Initialize()
    {
        if(!m_projectionTypes.empty()) { return; }

        m_projectionTypes[ProjectionType::Orthographic] = []
        {
            return std::make_unique<OrthographicProjection>(glm::vec3(0.0f), glm::vec3(1.0f), c_defaultNear, c_defaultFar);
        };

        m_projectionTypes[ProjectionType::Perspective] = []
        {
            return std::make_unique<PerspectiveProjection>(45.0f, 1.0f, c_defaultNear, c_defaultFar);
        };
    }

    std::unique_ptr<Projection> ProjectionFactory::CreateProjection(const ProjectionType _type)
    {
        Initialize();
        return m_projectionTypes[_type]();
    }
} // bombengine