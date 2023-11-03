//
// Created by s5311430 on 03/11/2023.
//

#include "perspectiveprojection.h"

#include <glm/ext/matrix_clip_space.hpp>

namespace bombengine
{
	PerspectiveProjection::PerspectiveProjection(const float _fieldOfView, const float _aspectRatio, const float _near, const float _far)
		: Projection(_near, _far),
		m_fieldOfView(_fieldOfView), m_aspectRatio(_aspectRatio)
	{ }

	glm::mat4 PerspectiveProjection::GetMatrix()
	{
		return glm::perspective(glm::radians(m_fieldOfView), m_aspectRatio, GetNear(), GetFar());
	}
} // bombengine