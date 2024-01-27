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
#include "components/wasd_component.h"
#include "components/camera_component.h"

using namespace std;
using namespace aoe_engine;

bool load_resources(ResourceManager* manager) {
	ShaderProgram* shader = new ShaderProgram("res/shaders/basic.vert", "res/shaders/basic.frag");

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

	ShaderProgram* transform_shader = new ShaderProgram("res/shaders/transform.vert", "res/shaders/basic.frag");

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

Entity* createSpinningBlock(float x, float y) {
	Entity* entity = new Entity();

	entity->registerComponent(new QuadComponent());

	TransformComponent* transform = new TransformComponent();
	transform->setTranslation(x, y);
	transform->setScaling(0.5f, 0.5f);
	transform->setRotation(45.0f);
	entity->registerComponent(transform);

	MotionComponent* motion = new MotionComponent();
	motion->setVelocity(0.00001f, 0.00001f);
	motion->setRotationalVelocity(0.01f);
	entity->registerComponent(motion);

	return entity;
}

Entity* createCamera() {
	Entity* camera = new Entity();
	camera->registerComponent(new TransformComponent());
	camera->registerComponent(new MotionComponent());
	camera->registerComponent(new WASDComponent());
	camera->registerComponent(new CameraComponent());
	return camera;
}

bool load_entities(Game* game) {
	Entity* block1 = createSpinningBlock(0.2f, 0.2f);
	game->addEntity(block1);

	Entity* block2 = createSpinningBlock(-0.4f, -0.4f);
	game->addEntity(block2);

	Entity* camera = createCamera();

	game->addEntity(camera);

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
