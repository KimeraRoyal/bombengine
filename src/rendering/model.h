//
// Created by Kimera Royal on 24/06/2023.
//

#pragma once

#include <vector>

#include "mesh.h"
#include "rendering/shader/shader_program.h"

#include "utility/unique_object.h"

namespace cpp_engine
{
	class Model : public UniqueObject
	{
	private:
		static size_t s_viewMatrixKey;
		static size_t s_projectionMatrixKey;
		static size_t s_modelMatrixKey;

		std::vector<std::shared_ptr<Mesh>> m_meshes;
	public:
		void Draw(const std::shared_ptr<ShaderProgram>& _program, const glm::mat4& _viewMatrix, const glm::mat4& _projectionMatrix, const glm::mat4& _modelMatrix) const;

		void AddMesh(const std::shared_ptr<Mesh>& _mesh);
		void AddMeshes(const std::vector<std::shared_ptr<Mesh>>& _meshes);
	};
} // cpp_engine
