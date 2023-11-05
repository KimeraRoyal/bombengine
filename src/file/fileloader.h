//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include <filesystem>

namespace bombengine
{
	class FileType;

	class FileLoader
	{
	private:
		std::filesystem::path m_basePath;

		std::filesystem::path GetAbsolutePath(const std::filesystem::path& _path);
	public:
		FileLoader();

		template<typename T>
		std::shared_ptr<T> Load(const std::filesystem::path& _path)
		{
			static_assert(std::is_base_of_v<FileType, T>);

			const std::filesystem::path absolutePath = GetAbsolutePath(_path);
			std::shared_ptr<T> file(new T);
			file->LoadFromPath(absolutePath);

			return file;
		}
	};

} // bombengine
