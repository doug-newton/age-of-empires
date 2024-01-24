#pragma once

#include "vao.h"

namespace aoe_engine {

	class QuadVao : public Vao {
	public:
		QuadVao();
		virtual ~QuadVao();

		virtual bool onInit();
	};

}
