#pragma once

#include <string>
#include <map>
#include "../graphics/resource.h"
#include "resource_exists_exception.h"

namespace aoe_engine {

	class ResourceMap {

	public:

		ResourceMap();
		~ResourceMap();

		bool onInit();

		void registerResource(const std::string& name, Resource* resource);
		Resource* getResource(const std::string& name);

	private:
		std::map<std::string, Resource*> m_resources;
	};

}
