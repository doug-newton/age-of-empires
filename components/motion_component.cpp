#include "motion_component.h"
#include "transform_component.h"
#include "../messages/change_transform_message.h"
#include "../messages/change_motion_message.h"

namespace aoe_engine {

	MotionComponent::MotionComponent() :
		Component("motion"),
		m_velocity(0.0f, 0.0f),
		m_scaling_velocity(0.0f, 0.0f),
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
		ChangeTransformMessage* message = new ChangeTransformMessage(this);
		message->setTranslationChange(this->m_velocity.x * delta, this->m_velocity.y * delta);
		message->setScalingChange(this->m_scaling_velocity.x * delta, this->m_scaling_velocity.y * delta);
		message->setRotationChange(this->m_rotational_velocity * delta);
		sendMessage(message);
	}

	void MotionComponent::onChangeMotionMessage(ChangeMotionMessage* message) {
		glm::vec2 new_velocity = message->getNewVelocity();
		this->m_velocity.x = new_velocity.x;
		this->m_velocity.y = new_velocity.y;
	}

}
