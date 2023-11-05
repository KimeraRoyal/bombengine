//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include "filetype.h"

namespace bombengine
{
	class TextFile : public FileType
	{
	private:
		std::string m_data;
	protected:
		friend class FileLoader;

		TextFile() = default;

		void LoadFromPath(const std::filesystem::path& _path) override;
	public:
		[[nodiscard]] std::string GetData() const { return m_data; }
	};

} // bombengine
