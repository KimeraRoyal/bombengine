//
// Created by s5311430 on 27/10/2023.
//

#pragma once

#include "mesh.h"
#include "rendering/shader/shaderprogram.h"

namespace bombengine
{
	class Model
	{
	private:
		static size_t s_viewMatrixKey;
		static size_t s_projectionMatrixKey;
		static size_t s_modelMatrixKey;

		std::vector<std::shared_ptr<Mesh>> m_meshes;
	public:
		void Draw(const ShaderProgram& _program, const glm::mat4& _viewMatrix, const glm::mat4& _projectionMatrix, const glm::mat4& _modelMatrix) const;

		void AddMesh(const std::shared_ptr<Mesh>& _mesh);
		void AddMesh(const std::vector<std::shared_ptr<Mesh>>& _meshes);
	};
} // bombengine
