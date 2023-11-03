//
// Created by s5311430 on 03/11/2023.
//

#include "camera.h"

#include <algorithm>

#include "rendering/renderable.h"

namespace bombengine
{
	Camera::Camera(std::unique_ptr<Projection> _projection, const SDL_Color &_clearColor, Uint32 _clearFlags)
		: m_projection(std::move(_projection)),
		m_clearColor(_clearColor), m_clearFlags(_clearFlags)
	{ }

	void Camera::Draw(const glm::mat4 &_viewMatrix)
	{
		glClearColor(static_cast<float>(m_clearColor.r) / 255.0f, static_cast<float>(m_clearColor.g) / 255.0f, static_cast<float>(m_clearColor.b) / 255.0f, static_cast<float>(m_clearColor.a) / 255.0f);
		glClear(m_clearFlags);

		for(auto& target : m_renderTargets)
		{
			target->Draw(_viewMatrix, GetProjectionMatrix());
		}
	}

	void Camera::AddRenderTarget(Renderable *_renderTarget)
	{
		m_renderTargets.push_back(_renderTarget);
	}

	void Camera::RemoveRenderTarget(const unsigned int _index)
	{
		m_renderTargets.erase(m_renderTargets.begin() + _index);
	}

	void Camera::RemoveRenderTarget(Renderable *_renderTarget)
	{
		m_renderTargets.erase(std::remove(m_renderTargets.begin(), m_renderTargets.end(), _renderTarget), m_renderTargets.end());
	}
} // bombengine