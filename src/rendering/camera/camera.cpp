//
// Created by s5311430 on 03/11/2023.
//

#include "camera.h"

#include <algorithm>
#include <SDL2/SDL_video.h>

#include "rendering/renderable.h"

namespace bombengine
{
	Camera::Camera(std::unique_ptr<Projection> _projection, const glm::vec4 _clearColor, Uint32 _clearFlags)
		: m_clearColor(_clearColor), m_clearFlags(_clearFlags),
		m_projection(std::move(_projection))
	{ }

	void Camera::Draw(const glm::mat4 &_viewMatrix) const
	{
		glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
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