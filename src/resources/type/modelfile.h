//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include "resources/resource.h"

#include <vector>
#include <memory>

#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "rendering/model/mesh.h"

namespace bombengine
{
	class ModelFile : public Resource
	{
	private:
		std::vector<std::shared_ptr<Mesh>> m_data;

		bool ProcessNode(const aiScene* _scene, const aiNode* _node);

		static std::shared_ptr<Mesh> ProcessMesh(const aiMesh* _mesh);
	protected:
		friend class Resources;

		explicit ModelFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path)
			: Resource(_resources, _path)
		{ }
	public:
		bool Load() override;

		[[nodiscard]] inline std::vector<std::shared_ptr<Mesh>> GetData() const { return m_data; }
	public:
	};
} // bombengine
