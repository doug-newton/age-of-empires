#pragma once

namespace aoe_engine {

	class FPS {
	public:
		FPS();
		float getDelta();
		void calcDelta();
	private:
		float m_delta;
		float m_last_time;
	};

}
