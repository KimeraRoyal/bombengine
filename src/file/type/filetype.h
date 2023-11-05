//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include <filesystem>

namespace bombengine
{
	class FileType
	{
	protected:
		friend class FileLoader;

		virtual void LoadFromPath(const std::filesystem::path& _path) = 0;
	};
}
