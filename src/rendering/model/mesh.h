//
// Created by s5311430 on 27/10/2023.
//

#pragma once

#include <memory>
#include <vector>

#include "vertex.h"
#include "vertexarray.h"

namespace bombengine
{
    class Mesh
    {
	private:
		std::shared_ptr<VertexArray> m_vertexArray;
		std::shared_ptr<VertexBuffer> m_vertices;
		std::shared_ptr<ElementBuffer> m_indices;

		bool m_depthTest;
		bool m_cullFaces;
	public:
		Mesh(const std::vector<Vertex>& _vertices, const std::vector<unsigned int>& _indices);

		void Draw() const;
    };

} // bombengine
