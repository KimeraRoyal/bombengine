//
// Created by Kimera Royal on 24/06/2023.
//

#ifndef CPP_ENGINE_VERTEX_H
#define CPP_ENGINE_VERTEX_H

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

namespace cpp_engine
{
	struct Vertex
	{
		glm::vec3 m_position;
		glm::vec3 m_normal;
		glm::vec2 m_uv;
	};
}

#endif //CPP_ENGINE_VERTEX_H
