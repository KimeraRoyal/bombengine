//
// Created by s5311430 on 27/10/2023.
//

#include "model.h"

namespace bombengine
{
	size_t Model::s_viewMatrixKey = std::hash<std::string>()("in_View");
	size_t Model::s_projectionMatrixKey = std::hash<std::string>()("in_Projection");
	size_t Model::s_modelMatrixKey = std::hash<std::string>()("in_Model");

	void Model::Draw(const ShaderProgram& _program, const glm::mat4& _viewMatrix, const glm::mat4& _projectionMatrix, const glm::mat4& _modelMatrix) const
	{
		_program.SetHashedUniform(s_viewMatrixKey, _viewMatrix);
		_program.SetHashedUniform(s_projectionMatrixKey, _projectionMatrix);
		_program.SetHashedUniform(s_modelMatrixKey, _modelMatrix);

		for(const auto& mesh : m_meshes)
		{
			mesh->Draw();
		}
	}

	void Model::AddMesh(const std::shared_ptr<Mesh>& _mesh)
	{
		m_meshes.push_back(_mesh);
	}

	void Model::AddMesh(const std::vector<std::shared_ptr<Mesh>>& _meshes)
	{
		m_meshes.insert(m_meshes.end(), _meshes.begin(), _meshes.end());
	}
} // bombengine