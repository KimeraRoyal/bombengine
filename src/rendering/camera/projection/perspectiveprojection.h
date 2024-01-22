//
// Created by s5311430 on 03/11/2023.
//

#pragma once

#include "projection.h"

namespace bombengine
{
	class PerspectiveProjection final : public Projection
	{
	private:
		float m_fieldOfView;
		float m_aspectRatio;
	public:
		PerspectiveProjection(float _fieldOfView, float _aspectRatio, float _near, float _far);

		glm::mat4 GetMatrix() override;

		[[nodiscard]] float GetFieldOfView() const { return m_fieldOfView; }
		void SetFieldOfView(const float _fieldOfView) { m_fieldOfView = _fieldOfView; }

		[[nodiscard]] float GetAspectRatio() const { return m_aspectRatio; }
		void SetAspectRatio(const float _aspectRatio) { m_aspectRatio = _aspectRatio; }
	};
} // bombengine
