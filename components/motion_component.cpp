#include "motion_component.h"
#include "transform_component.h"
#include "../messages/change_motion_message.h"
#include "../core/entity.h"

namespace aoe_engine {

	MotionComponent::MotionComponent() :
		Component("motion"),
		MotionSubject("motion") {
	}

	MotionComponent::~MotionComponent() {
	}

	void MotionComponent::onSetParent() {
		registerSubject(this->getParent());
	}

	void MotionComponent::onUpdate(float delta) {
		this->delta = delta;
		publish();
	}

	void MotionComponent::onChangeMotionMessage(ChangeMotionMessage* message) {
		glm::vec2 new_velocity = message->getNewVelocity();
		this->velocity.x = new_velocity.x;
		this->velocity.y = new_velocity.y;
	}

}
