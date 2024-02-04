#include "change_transform_message.h"
#include "../core/component.h"

namespace aoe_engine {

	ChangeTransformMessage::ChangeTransformMessage(void* sender) :
		Message(sender),
		m_translation_change(0.0f, 0.0f),
		m_scaling_change(0.0f, 0.0f),
		m_rotation_change(0.0f) {
	}

	ChangeTransformMessage::ChangeTransformMessage(
		void* sender, 
		const glm::vec2& translation_change, 
		const glm::vec2& scaling_change, 
		float rotation_change) :

		Message(sender),
		m_translation_change(translation_change),
		m_scaling_change(scaling_change),
		m_rotation_change(rotation_change) {
	}

	ChangeTransformMessage::~ChangeTransformMessage() {
	}

	void ChangeTransformMessage::accept(Component* component) {
		component->onChangeTransformMessage(this);
	}

	glm::vec2 ChangeTransformMessage::getTranslationChange() {
		return this->m_translation_change;
	}

	glm::vec2 ChangeTransformMessage::getScalingChange() {
		return this->m_scaling_change;
	}

	float ChangeTransformMessage::getRotationChange() {
		return this->m_rotation_change;
	}

	void ChangeTransformMessage::setTranslationChange(float x, float y) {
		this->m_translation_change.x = x;
		this->m_translation_change.y = y;
	}

	void ChangeTransformMessage::setScalingChange(float x, float y) {
		this->m_scaling_change.x = x;
		this->m_scaling_change.y = y;
	}

	void ChangeTransformMessage::setRotationChange(float r) {
		this->m_rotation_change = r;
	}

}
