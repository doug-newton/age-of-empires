#include "transform_message.h"
#include "../components/transform_component.h"

namespace aoe_engine {

	TransformMessage::TransformMessage(void* sender, const glm::vec2& velocity, float r_velocity) :
		Message(sender),
		m_velocity(velocity),
		m_rotational_velocity(r_velocity) {
	}

	TransformMessage::~TransformMessage() {
	}

	void TransformMessage::visitTransformComponent(TransformComponent* component) {
		glm::vec2 current_translation = component->getTranslation();

		component->setTranslation(
			current_translation.x + m_velocity.x,
			current_translation.y + m_velocity.y
		);

		float current_rotation = component->getRotation();

		component->setRotation(
			current_rotation + m_rotational_velocity
		);
	}

}
