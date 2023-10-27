//
// Created by s5311430 on 27/10/2023.
//

#include "mesh.h"

namespace bombengine
{
	Mesh::Mesh(const std::vector<Vertex>& _vertices, const std::vector<unsigned int>& _indices)
		: m_depthTest(true), m_cullFaces(true)
	{
		m_vertexArray = std::make_shared<VertexArray>();
		m_vertices = std::make_shared<VertexBuffer>();
		m_indices = std::make_shared<ElementBuffer>();
		if(!m_vertexArray && m_vertices && m_indices)
		{
			throw std::runtime_error("Could not generate Vertex Array Object and associated buffers.");
		}

		m_vertices->AddInterleavedSection(3, offsetof(Vertex, m_position));
		m_vertices->AddInterleavedSection(3, offsetof(Vertex, m_normal));
		m_vertices->AddInterleavedSection(2, offsetof(Vertex, m_uv));

		for(auto vertex : _vertices)
		{
			m_vertices->AddValue(reinterpret_cast<float*>(&vertex), 8);
		}

		for(const auto& index : _indices)
		{
			m_indices->AddValue(index);
		}

		m_vertexArray->AddVertexBuffer(m_vertices);
		m_vertexArray->SetElementBuffer(m_indices);
	}

	void Mesh::Draw() const
	{
		if(m_depthTest) { glEnable(GL_DEPTH_TEST); }
		else { glDisable(GL_DEPTH_TEST); }

		if(m_cullFaces) { glEnable(GL_CULL_FACE); }
		else { glDisable(GL_CULL_FACE); }

		m_vertexArray->Draw();

		if(m_cullFaces) { glDisable(GL_CULL_FACE); }
		if(m_depthTest) { glDisable(GL_DEPTH_TEST); }
	}
} // bombengine