#include "motion_component.h"
#include "transform_component.h"

namespace aoe_engine {

	MotionComponent::MotionComponent() :
		Component("motion"),
		m_velocity(0.0f, 0.0f),
		m_rotational_velocity(0.0f),
		m_transform_component(nullptr) {
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

	bool MotionComponent::onInit() {
		this->m_transform_component = getComponent<TransformComponent>("transform");

		if (this->m_transform_component == nullptr) {
			return false;
		}

		return true;
	}

	void MotionComponent::onUpdate(float delta) {
		glm::vec2 current_translation = this->m_transform_component->getTranslation();

		this->m_transform_component->setTranslation(
			current_translation.x + m_velocity.x * delta,
			current_translation.y + m_velocity.y * delta
		);

		float current_rotation = this->m_transform_component->getRotation();

		this->m_transform_component->setRotation(
			current_rotation + m_rotational_velocity * delta
		);
	}

}
