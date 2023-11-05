//
// Created by Kimera Royal on 05/11/2023.
//

#include "fileloader.h"

#include <SDL2/SDL_filesystem.h>

namespace bombengine
{
	FileLoader::FileLoader()
	{
		char* sdlBasePath = SDL_GetBasePath();

		std::string basePath(sdlBasePath);
		std::replace(basePath.begin(), basePath.end(), '\\', '/');
		m_basePath = basePath;

		SDL_free(sdlBasePath);
	}

	std::filesystem::path FileLoader::GetAbsolutePath(const std::filesystem::path &_path)
	{
		std::filesystem::path filePath(_path);
		if(filePath.is_relative())
		{
			filePath = m_basePath / _path;
		}

		return filePath;
	}
} // bombengine