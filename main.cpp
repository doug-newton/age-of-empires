#include "core/driver.h"
#include "graphics/shader_program.h"
#include "core/resource_manager.h"
#include "graphics/quad_vao.h";
#include "graphics/sprite_vao.h";
#include "core/component.h"
#include "components/quad_component.h"
#include "core/game.h"
#include "core/entity.h"
#include "components/transform_component.h"
#include "components/motion_component.h"
#include "components/wasd_component.h"
#include "components/camera_component.h"
#include "components/sprite_component.h"

using namespace std;
using namespace aoe_engine;

bool create_and_register_shader(
	ResourceManager* manager,
	const std::string& name,
	const std::string& vertex_source,
	const std::string& fragment_source
) {
	ShaderProgram* shader = new ShaderProgram(vertex_source, fragment_source);

	if (!shader->onInit()) {
		delete shader;
		return false;
	}

	try {
		manager->registerShaderProgram(name, shader);
	}
	catch (resource_exists_exception ex) {
		delete shader;
		return false;
	}

	return true;
}

bool load_resources(ResourceManager* manager) {
	if (!create_and_register_shader(
		manager,
		"basic",
		"res/shaders/basic.vert",
		"res/shaders/basic.frag")) {
		return false;
	}

	if (!create_and_register_shader(
		manager,
		"transform",
		"res/shaders/transform.vert",
		"res/shaders/basic.frag")) {
		return false;
	}

	if (!create_and_register_shader(
		manager,
		"texture",
		"res/shaders/texture.vert",
		"res/shaders/texture.frag")) {
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

	Vao* sprite = new SpriteVao();

	if (!sprite->onInit()) {
		delete sprite;
		return false;
	}

	try {
		manager->registerVao("sprite", sprite);
	}
	catch (resource_exists_exception ex) {
		delete sprite;
		return false;
	}

	Texture* tilesheet = new Texture("res/images/tilesheet.png");

	if (!tilesheet->onInit()) {
		delete tilesheet;
		return false;
	}

	try {
		manager->registerTexture("tilesheet", tilesheet);
	}
	catch (resource_exists_exception ex) {
		delete tilesheet;
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

Entity* createTexturedSpinningBlock(float x, float y) {
	Entity* entity = new Entity();

	entity->registerComponent(new SpriteComponent("tilesheet"));

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

	Entity* block2 = createTexturedSpinningBlock(-0.4f, -0.4f);
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
