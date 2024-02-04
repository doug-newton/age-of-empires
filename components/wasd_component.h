#pragma once

#include "../core/component.h"

namespace aoe_engine {

	class ChangeMotionMessage;

	class WASDComponent : public Component {
	public:
		WASDComponent();
		virtual ~WASDComponent();

		virtual void onKeyEvent(int key, int scanCode, int action, int mods) override;

	private:
		float m_speed;

		void goUp();
		void goDown();
		void goLeft();
		void goRight();
		void stop();
	};

}
