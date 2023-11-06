//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include "resources/resource.h"

#include <glm/ext/vector_int2.hpp>

namespace bombengine
{
	class ImageFile : public Resource
	{
	private:
		unsigned char* m_data;

		glm::ivec2 m_size;

	protected:
		friend class Resources;

		explicit ImageFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path)
			: Resource(_resources, _path),
			m_data(nullptr),
			m_size(0)
		{ }
	public:
		bool Load() override;
		~ImageFile();

		[[nodiscard]] unsigned char* GetData() const { return m_data; }

		[[nodiscard]] glm::ivec2 GetSize() const { return m_size; }
	};
} // bombengine
