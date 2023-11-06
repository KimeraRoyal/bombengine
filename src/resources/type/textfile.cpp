//
// Created by Kimera Royal on 05/11/2023.
//

#include "textfile.h"

#include <fstream>
#include <sstream>

#include <iostream>
#include <cstring>

namespace bombengine
{
	bool TextFile::Load()
	{
		std::ifstream fileStream(GetPath(), std::ifstream::in);
		std::stringstream buffer;

		if(fileStream.fail())
		{
			std::cerr << "Error opening text file at path: " << GetPath() << "\nError code: " << std::strerror(errno) << "\n";
			return false;
		}

		buffer << fileStream.rdbuf();
		fileStream.close();

		m_data = buffer.str();
		return true;
	}
} // bombengine