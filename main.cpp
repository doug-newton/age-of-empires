#include "core/driver.h"
#include "graphics/shader_program.h"
#include "core/resource_manager.h"
#include "graphics/quad_vao.h";
#include "core/component.h"
#include "components/quad_component.h"
#include "core/game.h"
#include "core/entity.h"

using namespace std;

bool load_resources(ResourceManager* manager) {
	ShaderProgram* shader = new ShaderProgram("res/basic.vert", "res/basic.frag");

	if (!shader->onInit()) {
		delete shader;
		return false;
	}

	try {
		manager->registerShaderProgram("basic", shader);
	}
	catch (resource_exists_exception ex) {
		delete shader;
		return false;
	}

	Vao* quad = new QuadVao();

	if (!quad->onInit()) {
		delete quad;
		return false;
	}

	try {
		manager->registerVao("quad", quad);
	}
	catch (resource_exists_exception ex) {
		delete quad;
		return false;
	}

	return true;
}

bool load_entities(Game* game) {
	Entity* entity = new Entity();
	entity->registerComponent(new QuadComponent());
	game->addEntity(entity);

	return true;
}

int main(int argc, char** argv)
{
	Driver::setResourceLoaderCallback(load_resources);
	Driver::setEntityLoaderCallback(load_entities);

	bool init_success = Driver::onInit();

	if (init_success) {
		Driver::run();
	}

	Driver::onCleanUp();

	return 0;
}
