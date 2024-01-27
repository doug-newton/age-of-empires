#pragma once

namespace aoe_engine {

	class FPS {
	public:
		FPS();
		float getDelta();
		void calcDelta();
	private:
		float delta;
		float lastTime;
	};

}
