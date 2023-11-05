//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include "filetype.h"

#include <glm/ext/vector_int2.hpp>

namespace bombengine
{
	class ImageFile : public FileType
	{
	private:
		unsigned char* m_data;

		glm::ivec2 m_size;
	protected:
		friend class FileLoader;

		ImageFile();

		void LoadFromPath(const std::filesystem::path& _path) override;
	public:
		~ImageFile();

		[[nodiscard]] unsigned char* GetData() const { return m_data; }

		[[nodiscard]] glm::ivec2 GetSize() const { return m_size; }
	};
} // bombengine
