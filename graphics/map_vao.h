#pragma once

#include "vao.h"

namespace aoe_engine {

	class MapVao : public Vao {

	public:
		MapVao();
		virtual ~MapVao();
		virtual bool onInit() override;

	};

}
