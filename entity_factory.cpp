#include "entity_factory.h"
#include "components/sprite_component.h"
#include "components/animated_sprite_component.h"
#include "components/transform_component.h"
#include "components/motion_component.h"
#include "components/wasd_component.h"
#include "components/view_component.h"
#include "components/click_collision_component.h"
#include "components/selection_component.h"
#include "components/click_mover_component.h"

#include "core/game.h"
#include "entities/world_map.h"

namespace aoe {

	using namespace aoe_engine;

	GameObject* EntityFactory::createMap(Game* game) {
		
		ResourceManager* manager = game->getResourceManager();
		ShaderProgram* shader_program = manager->getShaderProgram("texture");
		Texture* texture = manager->getTexture("tilesheet");
		Vao* vao = manager->getVao("map");

		WorldMap* world_map = new WorldMap(shader_program, texture, vao);

		return world_map;
	}

	Entity* EntityFactory::createVillager() {
		Entity* villager = new Entity();

		villager->registerComponent(new TransformComponent());
		villager->registerComponent(new AnimatedSpriteComponent("villager", "sprite"));
		villager->registerComponent(new ClickCollisionComponent());
		villager->registerComponent(new SelectionComponent());
		villager->registerComponent(new ClickMoverComponent());
		villager->registerComponent(new MotionComponent());

		return villager;
	}

}

