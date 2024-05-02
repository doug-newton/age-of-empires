#include "init.h"
#include "core/resource_manager.h"
#include "graphics/shader_program.h"
#include "graphics/quad_vao.h"
#include "graphics/sprite_vao.h"
#include "graphics/map_vao.h"
#include "core/game.h"
#include "entity_factory.h"
#include "camera/camera.h"
#include "entities/villager.h"

namespace aoe {

	using namespace aoe_engine;

	bool load_resources(ResourceManager* manager) {
		manager->registerShaderProgram("basic", new ShaderProgram("res/shaders/basic.vert", "res/shaders/basic.frag"));
		manager->registerShaderProgram("transform", new ShaderProgram("res/shaders/transform.vert", "res/shaders/basic.frag"));
		manager->registerShaderProgram("texture", new ShaderProgram("res/shaders/texture.vert", "res/shaders/texture.frag"));
		manager->registerShaderProgram("animated_texture", new ShaderProgram("res/shaders/animated_texture.vert", "res/shaders/animated_texture.frag"));

		manager->registerVao("quad", new QuadVao());
		manager->registerVao("sprite", new SpriteVao());
		manager->registerVao("map", new MapVao("res/maps/map.txt"));

		manager->registerTexture("tilesheet", new Texture("res/images/tilesheet.png"));
		manager->registerTexture("villager", new Texture("res/images/villager.png"));

		return true;
	}

	bool load_entities(Game* game) {
		Camera* camera1 = new Camera(16, { 0.0f, 0.0f });
		game->addGameObject(camera1);

		GameObject* map = aoe::EntityFactory::createMap(game);
		game->addGameObject(map);

		Entity* villager = aoe::EntityFactory::createVillager();
		game->addGameObject(villager);

		Villager* v2 = new Villager();
		game->addGameObject(v2);

		return true;
	}

}
