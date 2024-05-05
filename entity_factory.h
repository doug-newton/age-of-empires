#pragma once

#include "core/entity.h"
#include "core/game_object.h"

namespace aoe {

	class EntityFactory {
	public:
		static aoe_engine::Entity* createVillager();
	};
}

