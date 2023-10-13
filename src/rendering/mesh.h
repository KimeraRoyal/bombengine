//
// Created by Kimera Royal on 24/06/2023.
//

#pragma once

#include "vertex_array.h"
#include "rendering/texture/texture.h"

#include "vertex.h"

namespace cpp_engine
{
	class Mesh
	{
	private:
		std::shared_ptr<VertexArray> m_vao;
		std::shared_ptr<VertexBuffer> m_vertices;
		std::shared_ptr<ElementBuffer> m_indices;

		bool m_depthTest;
		bool m_cullFaces;
	public:
		 Mesh(const std::vector<Vertex>& _vertices, const std::vector<unsigned int>& _indices);

		 void Draw() const;

		 [[nodiscard]] inline bool GetCullFaces() const { return m_cullFaces; }
		 [[nodiscard]] inline GLenum GetDrawMode() const { return m_vao->GetDrawMode(); }

		 inline void SetCullFaces(const bool _cullFaces) { m_cullFaces = _cullFaces; }
		 inline void SetDrawMode(const GLenum _drawMode) { m_vao->SetDrawMode(_drawMode); }
	};
}