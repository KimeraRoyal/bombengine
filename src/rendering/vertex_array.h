//
// Created by Kimera Royal on 23/06/2023.
//

#pragma once

#include <memory>

#include "vertex_buffer.h"
#include "element_buffer.h"

namespace cpp_engine
{
	class VertexArray
	{
	private:
		GLuint m_id;

		std::vector<std::shared_ptr<VertexBuffer>> m_vbos;
		std::shared_ptr<ElementBuffer> m_ebo;

		GLenum m_drawMode;

		bool m_dirty;
	public:
		explicit VertexArray(GLenum _drawMode = GL_TRIANGLES);
		~VertexArray();

		void Draw();

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& _vbo);

		[[nodiscard]] GLuint GetID();

		[[nodiscard]] unsigned int GetVertexCount() const;
		[[nodiscard]] unsigned int GetIndexCount() const;

		[[nodiscard]] GLenum GetDrawMode() const { return m_drawMode; }

		void SetElementBuffer(const std::shared_ptr<ElementBuffer>& _ebo);

		inline void SetDrawMode(const GLenum _drawMode) { m_drawMode = _drawMode; }
	};
}
