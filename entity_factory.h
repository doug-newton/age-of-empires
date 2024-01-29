#pragma once

#include "core/entity.h"

namespace aoe {
	class EntityFactory {
	public:
		static aoe_engine::Entity* createMap();
		static aoe_engine::Entity* createCamera();
	};
}

