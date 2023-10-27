//
// Created by s5311430 on 27/10/2023.
//

#include "model.h"

namespace bombengine
{
	void Model::AddMesh(const std::shared_ptr<Mesh>& _mesh)
	{
		m_meshes.push_back(_mesh);
	}

	void Model::AddMesh(const std::vector<std::shared_ptr<Mesh>>& _meshes)
	{
		m_meshes.insert(m_meshes.end(), _meshes.begin(), _meshes.end());
	}
} // bombengine