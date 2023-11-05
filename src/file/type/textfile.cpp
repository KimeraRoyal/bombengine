//
// Created by Kimera Royal on 05/11/2023.
//

#include "textfile.h"

#include <fstream>
#include <sstream>

namespace bombengine
{
	void TextFile::LoadFromPath(const std::filesystem::path &_path)
	{
		std::ifstream fileStream(_path);
		std::stringstream buffer;

		buffer << fileStream.rdbuf();
		fileStream.close();

		m_data = buffer.str();
	}
} // bombengine