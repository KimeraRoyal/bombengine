//
// Created by Kimera Royal on 05/11/2023.
//

#include "modelfile.h"

#include <iostream>

#include <assimp/cimport.h>

namespace bombengine
{
	bool ModelFile::Load()
	{
		const aiScene* scene = aiImportFile(GetPath().string().c_str(),
			aiProcess_CalcTangentSpace |
			aiProcess_Triangulate |
			aiProcess_JoinIdenticalVertices |
			aiProcess_SortByPType);

		if(!ProcessNode(scene, scene->mRootNode))
		{
			std::cerr << "Error opening model file at path: " << GetPath() << "\n";
			return false;
		}
		aiReleaseImport(scene);

		return true;
	}

	bool ModelFile::ProcessNode(const aiScene *_scene, const aiNode *_node) // NOLINT(misc-no-recursion)
	{
		for(auto meshIndex = 0; meshIndex < _node->mNumMeshes; meshIndex++)
		{
			const std::shared_ptr<Mesh> mesh = ProcessMesh(_scene->mMeshes[_node->mMeshes[meshIndex]]);
			if(!mesh)
			{
				std::cerr << "Error processing mesh i: " << meshIndex << "\n";
				return false;
			}
			m_data.push_back(mesh);
		}

		for(auto childIndex = 0; childIndex < _node->mNumChildren; childIndex++)
		{
			if(!ProcessNode(_scene, _node->mChildren[childIndex])) { return false; }
		}

		return true;
	}

	std::shared_ptr<Mesh> ModelFile::ProcessMesh(const aiMesh *_mesh)
	{
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;

		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 uv;

		vertices.reserve(_mesh->mNumVertices);
		for(auto vertexIndex = 0; vertexIndex < _mesh->mNumVertices; vertexIndex++)
		{
			position = glm::vec3(_mesh->mVertices[vertexIndex].x, _mesh->mVertices[vertexIndex].y, _mesh->mVertices[vertexIndex].z);
			normal = glm::vec3(_mesh->mNormals[vertexIndex].x, _mesh->mNormals[vertexIndex].y, _mesh->mNormals[vertexIndex].z);
			if(_mesh->mTextureCoords[0]) { uv = glm::vec2(_mesh->mTextureCoords[0][vertexIndex].x, _mesh->mTextureCoords[0][vertexIndex].y); }
			else { uv = glm::vec2(0.0f); }

			vertices.emplace_back(position, normal, uv);
		}

		for(auto faceIndex = 0; faceIndex < _mesh->mNumFaces; faceIndex++)
		{
			indices.insert(indices.end(), _mesh->mFaces[faceIndex].mIndices, _mesh->mFaces[faceIndex].mIndices + _mesh->mFaces[faceIndex].mNumIndices);
		}

		return std::make_shared<Mesh>(vertices, indices);
	}
} // bombengine