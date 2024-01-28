#include "core/driver.h"
#include "graphics/shader_program.h"
#include "core/resource_manager.h"
#include "graphics/quad_vao.h";
#include "graphics/sprite_vao.h";
#include "graphics/map_vao.h";
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

bool load_and_register_vao(ResourceManager* manager, const std::string& name, Vao* vao) {
	if (!vao->onInit()) {
		delete vao;
		return false;
	}

	try {
		manager->registerVao(name, vao);
	}
	catch (resource_exists_exception ex) {
		delete vao;
		return false;
	}

	return true;
}

bool load_and_register_texture(ResourceManager* manager, const std::string& name, Texture* texture) {
	if (!texture->onInit()) {
		delete texture;
		return false;
	}

	try {
		manager->registerTexture(name, texture);
	}
	catch (resource_exists_exception ex) {
		delete texture;
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

	if (!load_and_register_vao(manager, "quad", new QuadVao())) {
		return false;
	}

	if (!load_and_register_vao(manager, "sprite", new SpriteVao())) {
		return false;
	}

	if (!load_and_register_vao(manager, "map", new MapVao("res/maps/map.txt"))) {
		return false;
	}

	if (!load_and_register_texture(manager, "tilesheet", new Texture("res/images/tilesheet.png"))) {
		return false;
	}

	return true;
}

Entity* create_map() {
	Entity* entity = new Entity();

	entity->registerComponent(new SpriteComponent("tilesheet", "map"));

	TransformComponent* transform = new TransformComponent();
	entity->registerComponent(transform);

	return entity;
}

Entity* create_camera() {
	Entity* camera = new Entity();

	TransformComponent* tc = new TransformComponent();
	tc->setScaling(0.0625f, 0.0625f);
	camera->registerComponent(tc);

	camera->registerComponent(new MotionComponent());
	camera->registerComponent(new WASDComponent());
	camera->registerComponent(new CameraComponent({"transform", "texture"}));
	return camera;
}

bool load_entities(Game* game) {
	Entity* camera = create_camera();
	game->addEntity(camera);

	Entity* map = create_map();
	game->addEntity(map);

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
