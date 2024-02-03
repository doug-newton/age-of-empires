#include "change_transform_message.h"
#include "../core/component.h"

namespace aoe_engine {

	ChangeTransformMessage::ChangeTransformMessage(
		void* sender, 
		const glm::vec2& translation_change, 
		float rotation_change) :

		Message(sender),
		m_translation_change(translation_change),
		m_rotation_change(rotation_change) {
	}

	ChangeTransformMessage::~ChangeTransformMessage() {
	}

	void ChangeTransformMessage::accept(Component* component) {
		component->onChangeTransformMessage(this);
	}

	glm::vec2 ChangeTransformMessage::getVelocity() {
		return this->m_translation_change;
	}

	float ChangeTransformMessage::getRotationalVelocity() {
		return this->m_rotation_change;
	}

}
