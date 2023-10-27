//
// Created by s5311430 on 20/10/2023.
//

#pragma once

#include <memory>

#include "buffer.h"

namespace bombengine
{
	typedef Buffer<float> VertexBuffer;
	typedef Buffer<unsigned int> ElementBuffer;

	class VertexArray
	{
	private:
		GLuint m_id;

		std::vector<std::shared_ptr<VertexBuffer>> m_vertexBufferObjects;
		std::shared_ptr<ElementBuffer> m_elementBufferObject;

		GLenum m_drawMode;

		bool m_dirty;
	public:
		explicit VertexArray(GLenum _drawMode = GL_TRIANGLES);
		~VertexArray();

		void Draw();

		void AddVertexBuffer(const std::shared_ptr<Buffer<float>>& _vertexBufferObject)
		{
			m_vertexBufferObjects.push_back(_vertexBufferObject);
			m_dirty = true;
		}

		void SetElementBuffer(const std::shared_ptr<Buffer<unsigned int>>& _elementBufferObject)
		{
			m_elementBufferObject = _elementBufferObject;
			m_dirty = true;
		}

		[[nodiscard]] GLuint GetID();

		[[nodiscard]] unsigned int GetVertexCount() const;
		[[nodiscard]] unsigned int GetIndexCount() const;

		[[nodiscard]] GLenum GetDrawMode() const { return m_drawMode; }
		void SetDrawMode(const GLenum _drawMode) { m_drawMode = _drawMode; }
	};
} // bombengine
