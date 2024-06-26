#pragma once

#include "../core/component.h"
#include <glm/glm.hpp>
#include "../subjects/motion_subject.h"
#include "../subjects/cardinal_movement_subject.h"

namespace aoe_engine {

	class MotionComponent : public Component, public MotionSubject {
	public:

		MotionComponent();
		virtual ~MotionComponent();

		bool onInit() override;
		void onUpdate(float delta) override;
		void onEntityRegistration() override;

		void onMovementUpdate(const MovementSubject* subject) override;
		void onCardinalMovementUpdate(const CardinalMovementSubject* subject) override;

	private:
		float m_speed;

	};

}
