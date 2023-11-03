//
// Created by s5311430 on 03/11/2023.
//

#include "orthographicprojection.h"

#include "glm/ext/matrix_clip_space.hpp"

namespace bombengine
{
	OrthographicProjection::OrthographicProjection(const glm::vec2 &_min, const glm::vec2 &_max, float _near, float _far)
		: Projection(_near, _far),
		m_min(_min), m_max(_max)
	{ }

	glm::mat4 OrthographicProjection::GetMatrix()
	{
		return glm::ortho(m_min.x, m_max.x, m_min.y, m_max.y, GetNear(), GetFar());
	}
} // bombengine