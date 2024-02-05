#include "entity_factory.h"
#include "components/sprite_component.h"
#include "components/animated_sprite_component.h"
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

	Entity* EntityFactory::createVillager() {
		Entity* villager = new Entity();

		TransformComponent* tc = new TransformComponent();
		villager->registerComponent(tc);

		villager->registerComponent(new AnimatedSpriteComponent("villager", "sprite"));

		return villager;
	}

}

