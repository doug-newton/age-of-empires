#pragma once

#include <string>
#include <map>

namespace aoe_engine {

	template <class ResourceType>
	class GenericResourceManager {

	public:

		GenericResourceManager() {
		}

		~GenericResourceManager() {
			for (auto it = m_resources.begin(); it != m_resources.end(); ++it) {
				delete (*it).second;
			}
		}

		void registerResource(const std::string& name, ResourceType* resource) {
			if (m_resources.find(name) != m_resources.end()) {
				throw new resource_exists_exception();
			}

			m_resources[name] = resource;
		}

		ResourceType* getResource(const std::string& name) {
			auto result = m_resources.find(name);

			if (result == m_resources.end()) {
				return nullptr;
			}

			return (*result).second;
		}

	private:
		std::map<std::string, ResourceType*> m_resources;
	};

}
