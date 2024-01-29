#include "resource_map.h"

namespace aoe_engine {

	ResourceMap::ResourceMap() {
	}

	ResourceMap::~ResourceMap() {
		for (auto it = m_resources.begin(); it != m_resources.end(); ++it) {
			delete (*it).second;
		}
	}

	bool ResourceMap::onInit() {
		bool success = true;

		for (auto it = m_resources.begin(); it != m_resources.end(); ++it) {
			success = success && ((*it).second)->onInit();
		}

		return success;
	}

	void ResourceMap::registerResource(const std::string& name, Resource* resource) {
		if (m_resources.find(name) != m_resources.end()) {
			delete resource;
			throw new resource_exists_exception();
		}

		m_resources[name] = resource;
	}

	Resource* ResourceMap::getResource(const std::string& name) {
		auto result = m_resources.find(name);

		if (result == m_resources.end()) {
			return nullptr;
		}

		return (*result).second;
	}


}
