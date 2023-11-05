//
// Created by Kimera Royal on 05/11/2023.
//

#include "imagefile.h"

#include <stb/stb_image.h>

namespace bombengine
{
	ImageFile::ImageFile()
		: m_data(nullptr),
		m_size(glm::ivec2(0))
	{ }

	ImageFile::~ImageFile()
	{
		if(m_data) { free(m_data); }
	}

	void ImageFile::LoadFromPath(const std::filesystem::path &_path)
	{
		m_data = stbi_load(_path.string().c_str(), &m_size.x, &m_size.y, nullptr, STBI_rgb_alpha);
		if(!m_data) { throw std::runtime_error("Could not load Image File."); }
	}
} // bombengine