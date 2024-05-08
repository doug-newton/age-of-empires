#include "init.h"
#include "core/resource_manager.h"
#include "graphics/shader_program.h"
#include "graphics/sprite_vao.h"
#include "graphics/map_vao.h"
#include "core/game.h"
#include "entity_factory.h"
#include "camera/camera.h"
#include "entities/villager.h"
#include "entities/world_map.h"

namespace aoe {

	using namespace aoe_engine;

	bool load_resources(ResourceManager* manager) {

		manager->registerShaderProgram("basic", new ShaderProgram("basic"));
		manager->registerShaderProgram("transform", new ShaderProgram("transform"));
		manager->registerShaderProgram("texture", new ShaderProgram("texture"));
		manager->registerShaderProgram("animated_texture", new ShaderProgram("animated_texture"));

		manager->registerVao("sprite", new SpriteVao("sprite"));

		manager->registerTexture("tilesheet", new Texture("res/images/tilesheet.png"));
		manager->registerTexture("villager", new Texture("res/images/villager.png"));

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
