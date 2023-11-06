//
// Created by Kimera Royal on 05/11/2023.
//

#include "imagefile.h"

#include <iostream>

#include <stb/stb_image.h>

namespace bombengine
{
	ImageFile::~ImageFile()
	{
		if(m_data) { free(m_data); }
	}

	bool ImageFile::Load()
	{
		m_data = stbi_load(GetPath().string().c_str(), &m_size.x, &m_size.y, nullptr, STBI_rgb_alpha);
		if(!m_data)
		{
			std::cerr << "Error opening image file at path: " << GetPath() << "\nError code: " << stbi_failure_reason() << "\n";
			return false;
		}

		return true;
	}
} // bombengine