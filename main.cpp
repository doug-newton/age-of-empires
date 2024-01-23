#include "core/driver.h"
#include "graphics/shader_program.h"
#include "core/resource_manager.h"
#include "graphics/quad_vao.h";
#include "core/component.h"
#include "components/quad_component.h"
#include "core/game.h"
#include "core/entity.h"
#include "components/transform_component.h"
#include "components/motion_component.h"

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

	ShaderProgram* transform_shader = new ShaderProgram("res/transform.vert", "res/basic.frag");

	if (!transform_shader->onInit()) {
		delete transform_shader;
		return false;
	}

	try {
		manager->registerShaderProgram("transform", transform_shader);
	}
	catch (resource_exists_exception ex) {
		delete transform_shader;
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

	TransformComponent* transform = new TransformComponent();
	transform->setTranslation(0.2f, 0.2f);
	transform->setScaling(0.5f, 0.5f);
	transform->setRotation(45.0f);
	entity->registerComponent(transform);

	MotionComponent* motion = new MotionComponent();
	motion->setVelocity(0.00001f, 0.00001f);
	motion->setRotationalVelocity(0.01f);
	entity->registerComponent(motion);

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
