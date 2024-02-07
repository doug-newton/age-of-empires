#pragma once

#include "../core/component.h"
#include "../subjects/movement_subject.h"

namespace aoe_engine {

	class ChangeMotionMessage;

	class WASDComponent : public Component, public MovementSubject {
	public:
		WASDComponent();
		virtual ~WASDComponent();

		void onSetParent() override;

		virtual void onKeyEvent(int key, int scanCode, int action, int mods) override;

	private:
		float m_speed;
	};

}
