#pragma once

namespace aoe_engine {
	class ResourceManager;
	class Game;
}

namespace aoe {

	using namespace aoe_engine;

	bool load_resources(ResourceManager* manager);
	bool load_entities(Game* game);

}

