//
// Created by s5311430 on 03/11/2023.
//

#pragma once

#include "glm/mat4x4.hpp"

namespace bombengine
{
	class Projection
	{
	private:
		float m_near;
		float m_far;
	public:
		Projection(const float _near, const float _far)
			: m_near(_near), m_far(_far)
		{ }

		virtual glm::mat4 GetMatrix() = 0;

		[[nodiscard]] float GetNear() const { return m_near; }
		void SetNear(const float _near) { m_near = _near; }

		[[nodiscard]] float GetFar() const { return m_near; }
		void SetFar(const float _near) { m_near = _near; }
	};
}