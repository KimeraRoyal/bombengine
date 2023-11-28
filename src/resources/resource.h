//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include <filesystem>

namespace bombengine
{
	class Resources;

	class Resource
	{
	private:
		std::weak_ptr<Resources> m_resources;

		std::filesystem::path m_path;
	protected:
		friend class Resources;

		explicit Resource(const std::shared_ptr<Resources>& _resources, const std::filesystem::path& _path);
	public:
		virtual ~Resource() = default;

		virtual bool Load() = 0;

		[[nodiscard]] std::shared_ptr<Resources> GetResources() const;

		[[nodiscard]] std::filesystem::path GetPath() const { return m_path; }
	};
}
