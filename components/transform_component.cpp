#include "transform_component.h"

TransformComponent::TransformComponent() :
	Component("transform"),
	m_translation(0.0f, 0.0f),
	m_scaling(1.0f, 1.0f),
	m_rotation(0.0f) {
}

TransformComponent::~TransformComponent() {
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
