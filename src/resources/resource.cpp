//
// Created by Kimera Royal on 05/11/2023.
//

#include "resource.h"

#include "resources.h"

namespace bombengine
{
	Resource::Resource(const std::shared_ptr<Resources>& _resources, const std::filesystem::path &_path)
		: m_resources(_resources),
		m_path(_path)
	{ }

	std::shared_ptr<Resources> Resource::GetResources() const
	{
		std::shared_ptr<Resources> resources = m_resources.lock();
		if(!resources) { throw std::runtime_error("Failed to retrieve pointer to Resources."); }
		return resources;
	}
}
