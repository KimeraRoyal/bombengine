//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include <filesystem>
#include <map>
#include <memory>

namespace bombengine
{
	class Resource;

	class Resources : public std::enable_shared_from_this<Resources>
	{
	private:
		std::filesystem::path m_basePath;

		std::unordered_map<size_t, std::shared_ptr<Resource>> m_cachedResources;

		std::filesystem::path GetAbsolutePath(const std::filesystem::path& _path);

		template<typename T>
		std::shared_ptr<T> LoadResource(const std::filesystem::path& _path)
		{
			std::shared_ptr<T> resource = std::shared_ptr<T>(new T(shared_from_this(), _path));
			if(!resource || !resource->Load()) { return nullptr; }

			m_cachedResources.insert(std::make_pair(std::hash<std::string>()(_path.string()), resource));
			return resource;
		}
	public:
		Resources();

		template<typename T>
		std::shared_ptr<T> GetResource(const std::filesystem::path& _path)
		{
			static_assert(std::is_base_of_v<Resource, T>);

			const std::filesystem::path absolutePath = GetAbsolutePath(_path);

			auto resourceIterator = m_cachedResources.find(std::hash<std::string>()(absolutePath.string()));
			if(resourceIterator == m_cachedResources.end())
			{
				return LoadResource<T>(absolutePath);
			}
			else
			{
				return std::static_pointer_cast<T>(resourceIterator->second);
			}
		}

		template<typename T>
		std::shared_ptr<T> FindResource(size_t _key)
		{
			static_assert(std::is_base_of_v<Resource, T>);

			auto resourceIterator = m_cachedResources.find(_key);
			if(resourceIterator != m_cachedResources.end())
			{
				return std::static_pointer_cast<T>(resourceIterator->second);
			}
		}
	};

} // bombengine
