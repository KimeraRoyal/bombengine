//
// Created by Kimera Royal on 22/01/2024.
//

#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include "projection.h"
#include "projectiontype.h"

namespace bombengine
{
    class ProjectionFactory
    {
    private:
        static const float c_defaultNear;
        static const float c_defaultFar;

        static std::unordered_map<ProjectionType, std::function<std::unique_ptr<Projection>()>> m_projectionTypes;

        ProjectionFactory() = default;

        static void Initialize();
    public:
        static std::unique_ptr<Projection> CreateProjection(ProjectionType _type);
    };
} // bombengine
