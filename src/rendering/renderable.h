//
// Created by s5311430 on 03/11/2023.
//

#pragma once

#include "glm/mat4x4.hpp"

namespace bombengine
{
	class Renderable
	{
	public:
		virtual void Draw(const glm::mat4& _viewMatrix, const glm::mat4& _projectionMatrix) = 0;
	};
} // bombengine