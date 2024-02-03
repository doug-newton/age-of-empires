#include "change_transform_message.h"
#include "../core/component.h"

namespace aoe_engine {

	ChangeTransformMessage::ChangeTransformMessage(void* sender, const glm::vec2& velocity, float r_velocity) :
		Message(sender),
		m_velocity(velocity),
		m_rotational_velocity(r_velocity) {
	}

	ChangeTransformMessage::~ChangeTransformMessage() {
	}

	void ChangeTransformMessage::accept(Component* component) {
		component->onChangeTransformMessage(this);
	}

	glm::vec2 ChangeTransformMessage::getVelocity() {
		return this->m_velocity;
	}

	float ChangeTransformMessage::getRotationalVelocity() {
		return this->m_rotational_velocity;
	}

}
