//
// Created by Kimera Royal on 05/11/2023.
//

#include "resources.h"

#include <algorithm>

#include <SDL2/SDL_filesystem.h>

namespace bombengine
{
	Resources::Resources()
	{
		char* sdlBasePath = SDL_GetBasePath();

		std::string basePath(sdlBasePath);
		std::replace(basePath.begin(), basePath.end(), '\\', '/');
		m_basePath = basePath;

		SDL_free(sdlBasePath);
	}

	std::filesystem::path Resources::GetAbsolutePath(const std::filesystem::path &_path)
	{
		std::filesystem::path filePath(_path);
		if(filePath.is_relative())
		{
			filePath = m_basePath / _path;
		}

		return filePath;
	}

	void Resources::Update()
	{
		for(const auto& resourceToDelete : m_resourcesToDelete)
		{
			m_cachedResources.erase(resourceToDelete);
		}
		m_resourcesToDelete.clear();
	}

	void Resources::ReturnResource(const size_t _key)
	{
		m_resourcesToDelete.insert(_key);
	}

	void Resources::ReturnResource(const std::filesystem::path &_path)
	{
		ReturnResource(std::hash<std::string>()(_path.string()));
	}
} // bombengine