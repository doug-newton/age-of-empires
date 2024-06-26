#pragma once

#include "../core/component.h"
#include "../subjects/cardinal_movement_subject.h"

namespace aoe_engine {

	class ChangeMotionMessage;

	class WASDComponent : public Component, public CardinalMovementSubject {
	public:
		WASDComponent();
		virtual ~WASDComponent();

		void onEntityRegistration() override;

		virtual void onKeyEvent(int key, int scanCode, int action, int mods) override;

	private:
		float m_speed;
	};

}
