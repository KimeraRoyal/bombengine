//
// Created by s5311430 on 27/10/2023.
//

#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace bombengine
{
	struct Vertex
	{
		glm::vec3 m_position;
		glm::vec3 m_normal;
		glm::vec2 m_uv;
	};
}
