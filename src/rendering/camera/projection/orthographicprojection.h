//
// Created by s5311430 on 03/11/2023.
//

#pragma once

#include "projection.h"

namespace bombengine
{
	class OrthographicProjection final : public Projection
	{
	private:
		glm::vec2 m_min;
		glm::vec2 m_max;
	public:
		OrthographicProjection(glm::vec2 _min, glm::vec2 _max, float _near, float _far);

		glm::mat4 GetMatrix() override;

		[[nodiscard]] glm::vec2 GetMin() const { return m_min; }
		void SetMin(const glm::vec2 _min) { m_min = _min; }

		[[nodiscard]] glm::vec2 GetMax() const { return m_min; }
		void SetMax(const glm::vec2 _min) { m_min = _min; }
	};
} // bombengine
