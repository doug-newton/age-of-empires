#include "motion_component.h"
#include "../core/entity.h"
#include "../subjects/movement_subject.h"

namespace aoe_engine {

	MotionComponent::MotionComponent() :
		Component("motion"),
		MotionSubject("motion"),
		m_speed(0.5f) {
	}

	MotionComponent::~MotionComponent() {
	}

	bool MotionComponent::onInit() {
		subscribe("movement");
		return true;
	}

	void MotionComponent::onSetParent() {
		registerSubject(this->getParent());
	}

	void MotionComponent::onUpdate(float delta) {
		this->delta = delta;
		publish();
	}

	void MotionComponent::onMovementUpdate(const MovementSubject* subject) {
		this->velocity.x = this->velocity.y = 0;

		if (subject->moving_left) {
			this->velocity.x = -this->m_speed;
		}
		else if (subject->moving_right) {
			this->velocity.x = this->m_speed;
		}

		if (subject->moving_up) {
			this->velocity.y = this->m_speed;
		}
		else if (subject->moving_down) {
			this->velocity.y = -this->m_speed;
		}
	}

}
