#include "change_motion_message.h"
#include "../core/component.h"

namespace aoe_engine {

	ChangeMotionMessage::ChangeMotionMessage(Component* sender) :
		Message(sender),
		m_new_velocity(0.0f, 0.0f) {
	}

	ChangeMotionMessage::~ChangeMotionMessage() {
	}

	void ChangeMotionMessage::accept(Component* component) {
		component->onChangeMotionMessage(this);
	}

	void ChangeMotionMessage::setNewVelocity(float x, float y) {
		this->m_new_velocity.x = x;
		this->m_new_velocity.y = y;
	}

	glm::vec2 ChangeMotionMessage::getNewVelocity() {
		return this->m_new_velocity;
	}

}