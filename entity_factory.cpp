#include "entity_factory.h"
#include "components/sprite_component.h"
#include "components/transform_component.h"
#include "components/motion_component.h"
#include "components/wasd_component.h"
#include "components/camera_component.h"

namespace aoe {

	using namespace aoe_engine;

	Entity* EntityFactory::createMap() {
		Entity* entity = new Entity();

		entity->registerComponent(new SpriteComponent("tilesheet", "map"));

		TransformComponent* transform = new TransformComponent();
		entity->registerComponent(transform);

		return entity;
	}

	Entity* EntityFactory::createCamera() {
		Entity* camera = new Entity();

		TransformComponent* tc = new TransformComponent();
		tc->setScaling(16.0f, 16.0f);
		camera->registerComponent(tc);

		camera->registerComponent(new MotionComponent());
		camera->registerComponent(new WASDComponent());
		camera->registerComponent(new CameraComponent({ "transform", "texture" }));
		return camera;
	}

}

