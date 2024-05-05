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

