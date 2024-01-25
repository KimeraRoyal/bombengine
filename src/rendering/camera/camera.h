//
// Created by s5311430 on 03/11/2023.
//

#pragma once

#include <memory>
#include <vector>

#include <GL/glew.h>

#include "projection/projection.h"

#include "core/utility/color.h"

namespace bombengine
{
	class Renderable;

	class Camera
	{
	private:
		glm::vec4 m_clearColor;
		Uint32 m_clearFlags;

		std::unique_ptr<Projection> m_projection;

		std::vector<Renderable*> m_renderables;
	public:
		explicit Camera(std::unique_ptr<Projection> _projection, glm::vec4 _clearColor = Color::c_black, Uint32 _clearFlags = GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		void Draw(const glm::mat4& _viewMatrix) const;

		void AddRendererable(Renderable* _renderable);
		void RemoveRenderable(unsigned int _index);
		void RemoveRenderable(Renderable* _renderable);
		void RemoveAllRenderables();

		[[nodiscard]] glm::vec4 GetClearColor() const { return m_clearColor; }
		void SetClearColor(const glm::vec4 _color) { m_clearColor = _color; }

		[[nodiscard]] Uint32 GetClearFlags() const { return m_clearFlags; }
		void SetClearFlags(const Uint32 _flags) { m_clearFlags = _flags; }

		[[nodiscard]] glm::mat4 GetProjectionMatrix() const { return m_projection->GetMatrix(); }
	};
} // bombengine
