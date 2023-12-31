//
// Created by Kimera Royal on 05/11/2023.
//

#pragma once

#include <filesystem>
#include <unordered_map>
#include <unordered_set>
#include <memory>

namespace bombengine
{
	class Resource;

	class Resources : public std::enable_shared_from_this<Resources>
	{
	private:
		std::filesystem::path m_basePath;

		std::unordered_map<size_t, std::shared_ptr<Resource>> m_cachedResources;
		std::unordered_set<size_t> m_resourcesToDelete;

		std::filesystem::path GetAbsolutePath(const std::filesystem::path& _path);

		Resources();

		template<typename T>
		std::shared_ptr<T> LoadResource(const std::filesystem::path& _path)
		{
			std::shared_ptr<T> resource = std::shared_ptr<T>(new T(shared_from_this(), _path));
			if(!resource || !resource->Load()) { return nullptr; }

			m_cachedResources.insert(std::make_pair(std::hash<std::string>()(_path.string()), resource));
			return resource;
		}
	public:
		void Update();

		template<typename T>
		std::shared_ptr<T> GetResource(const std::filesystem::path& _path)
		{
			static_assert(std::is_base_of_v<Resource, T>);

			const std::filesystem::path absolutePath = GetAbsolutePath(_path);

			const auto resourceIterator = m_cachedResources.find(std::hash<std::string>()(absolutePath.string()));
			return resourceIterator == m_cachedResources.end() ? LoadResource<T>(absolutePath) : std::static_pointer_cast<T>(resourceIterator->second);
		}

		template<typename T>
		std::shared_ptr<T> FindResource(const size_t _key)
		{
			static_assert(std::is_base_of_v<Resource, T>);

			const auto resourceIterator = m_cachedResources.find(_key);
			return resourceIterator != m_cachedResources.end() ? std::static_pointer_cast<T>(resourceIterator->second) : nullptr;
		}

		void ReturnResource(size_t _key);
		void ReturnResource(const std::filesystem::path& _path);

		static std::shared_ptr<Resources> Initialize();
	};

} // bombengine
