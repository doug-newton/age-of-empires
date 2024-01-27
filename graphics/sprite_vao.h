#pragma once

#include "vao.h"

namespace aoe_engine {

	class SpriteVao : public Vao {
	public:
		SpriteVao();
		virtual ~SpriteVao();
		virtual bool onInit() override;
	};
}
