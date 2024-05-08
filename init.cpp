#include "init.h"
#include "core/resource_manager.h"
#include "graphics/shader_program.h"
#include "graphics/custom_vao.h"
#include "graphics/map_vao.h"
#include "core/game.h"
#include "entity_factory.h"
#include "camera/camera.h"
#include "entities/villager.h"
#include "entities/world_map.h"

namespace aoe {

	using namespace aoe_engine;

	bool load_resources(ResourceManager* manager) {

		return true;
	}

	bool load_entities(Game* game) {
		Camera* camera1 = new Camera(16, { 0.0f, 0.0f });
		game->addGameObject(camera1);

		GameObject* map = new WorldMap("res/maps/map.txt");
		game->addGameObject(map);

		Entity* villager = aoe::EntityFactory::createVillager();
		game->addGameObject(villager);

		Villager* v2 = new Villager();
		game->addGameObject(v2);

		return true;
	}

}
