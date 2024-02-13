#pragma once

namespace aoe_engine {

	struct MouseMoveEvent {
		int button;
		int action;
		int mods;
		double x;
		double y;
		double screen_width;
		double screen_height;
	};

}
