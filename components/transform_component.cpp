#include "transform_component.h"
#include "../subjects/motion_subject.h"

namespace aoe_engine {

	TransformComponent::TransformComponent() :
		Component("transform"),
		m_translation(0.0f, 0.0f),
		m_scaling(1.0f, 1.0f),
		m_rotation(0.0f) {
	}

	TransformComponent::~TransformComponent() {
	}

	bool TransformComponent::onInit() {
		subscribe("motion");
		return true;
	}

	const glm::vec2& TransformComponent::getTranslation() {
		return this->m_translation;
	}

	const glm::vec2& TransformComponent::getScaling() {
		return this->m_scaling;
	}

	float TransformComponent::getRotation() {
		return this->m_rotation;
	}

	glm::mat4 TransformComponent::createModelMatrix() {
		glm::mat4 model(1.0f);

		model = glm::translate(model, glm::vec3(this->m_translation, 0.0f));
		model = glm::scale(model, glm::vec3(this->m_scaling, 0.0f));
		model = glm::rotate(model, glm::radians(this->m_rotation), glm::vec3(0.0f, 0.0f, 1.0f));

		return model;
	}

	void TransformComponent::setTranslation(float x, float y) {
		this->m_translation.x = x;
		this->m_translation.y = y;
	}

	void TransformComponent::setScaling(float w, float h) {
		this->m_scaling.x = w;
		this->m_scaling.y = h;
	}

	void TransformComponent::setRotation(float r) {
		this->m_rotation = r;
	}

	void TransformComponent::onMotionUpdate(const MotionSubject* subject) {
		this->m_translation.x += subject->velocity.x * subject->delta;
		this->m_translation.y += subject->velocity.y * subject->delta;
	}

}
