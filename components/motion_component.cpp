#include "motion_component.h"
#include "transform_component.h"
#include "../messages/transform_message.h"

namespace aoe_engine {

	MotionComponent::MotionComponent() :
		Component("motion"),
		m_velocity(0.0f, 0.0f),
		m_rotational_velocity(0.0f) {
	}

	MotionComponent::~MotionComponent() {
	}

	void MotionComponent::setVelocity(float x, float y) {
		this->m_velocity.x = x;
		this->m_velocity.y = y;
	}

	void MotionComponent::setRotationalVelocity(float r) {
		this->m_rotational_velocity = r;
	}

	void MotionComponent::onUpdate(float delta) {
		sendMessage(new TransformMessage(this,
			this->m_velocity * delta,
			this->m_rotational_velocity * delta));
	}

}
