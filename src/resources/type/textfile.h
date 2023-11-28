//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include "resources/resource.h"

namespace bombengine
{
	class TextFile final : public Resource
	{
	private:
		std::string m_data;
	protected:
		friend class Resources;

		explicit TextFile(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path)
			: Resource(_resources, _path)
		{ }
	public:
		bool Load() override;

		[[nodiscard]] std::string GetData() const { return m_data; }
	};

} // bombengine
