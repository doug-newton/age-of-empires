#pragma once

#include "core/entity.h"
#include "core/game_object.h"
#include "core/game.h"

namespace aoe {

	class EntityFactory {
	public:
		static aoe_engine::GameObject* createMap(aoe_engine::Game* game);
		static aoe_engine::Entity* createVillager();
	};
}

