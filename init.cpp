#include "init.h"
#include "core/resource_manager.h"
#include "graphics/shader_program.h"
#include "graphics/quad_vao.h"
#include "graphics/sprite_vao.h"
#include "graphics/map_vao.h"
#include "core/game.h"
#include "entity_factory.h"

namespace aoe {

	using namespace aoe_engine;

	bool load_resources(ResourceManager* manager) {
		manager->registerShaderProgram("basic", new ShaderProgram("res/shaders/basic.vert", "res/shaders/basic.frag"));
		manager->registerShaderProgram("transform", new ShaderProgram("res/shaders/transform.vert", "res/shaders/basic.frag"));
		manager->registerShaderProgram("texture", new ShaderProgram("res/shaders/texture.vert", "res/shaders/texture.frag"));

		manager->registerVao("quad", new QuadVao());
		manager->registerVao("sprite", new SpriteVao());
		manager->registerVao("map", new MapVao("res/maps/map.txt"));

		manager->registerTexture("tilesheet", new Texture("res/images/tilesheet.png"));

		return true;
	}

	bool load_entities(Game* game) {
		Entity* camera = aoe::EntityFactory::createCamera();
		game->addEntity(camera);

		Entity* map = aoe::EntityFactory::createMap();
		game->addEntity(map);

		return true;
	}

}
