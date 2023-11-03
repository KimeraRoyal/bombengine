//
// Created by s5311430 on 03/11/2023.
//

#pragma once

#include <memory>
#include <vector>

#include <SDL2/SDL_pixels.h>
#include <GL/glew.h>

#include "projection/projection.h"

namespace bombengine
{
	class Renderable;

	class Camera
	{
	private:
		SDL_Color m_clearColor;
		Uint32 m_clearFlags;

		std::unique_ptr<Projection> m_projection;

		std::vector<Renderable*> m_renderTargets;
	public:
		explicit Camera(std::unique_ptr<Projection> _projection, const SDL_Color& _clearColor = SDL_Color(0x00, 0x00, 0x00, 0xFF), Uint32 _clearFlags = GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		void Draw(const glm::mat4& _viewMatrix);

		void AddRenderTarget(Renderable* _renderTarget);
		void RemoveRenderTarget(unsigned int _index);
		void RemoveRenderTarget(Renderable* _renderTarget);

		[[nodiscard]] SDL_Color GetClearColor() const { return m_clearColor; }
		void SetClearColor(const SDL_Color& _color) { m_clearColor = _color; }

		[[nodiscard]] Uint32 GetClearFlags() const { return m_clearFlags; }
		void SetClearFlags(const Uint32 _flags) { m_clearFlags = _flags; }

		[[nodiscard]] glm::mat4 GetProjectionMatrix() const { return m_projection->GetMatrix(); }
	};
} // bombengine
