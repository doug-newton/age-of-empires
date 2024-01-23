#include "transform_component.h"

TransformComponent::TransformComponent() :
	Component("transform"),
	m_position(0.0f, 0.0f),
	m_dimensions(1.0f, 1.0f),
	m_rotation(0.0f) {
}

TransformComponent::~TransformComponent() {
}

const glm::vec2& TransformComponent::getPosition() {
	return this->m_position;
}

const glm::vec2& TransformComponent::getDimensions() {
	return this->m_dimensions;
}

float TransformComponent::getRotation() {
	return this->m_rotation;
}

void TransformComponent::setPosition(float x, float y) {
	this->m_position.x = x;
	this->m_position.y = y;
}

void TransformComponent::setDimensions(float w, float h) {
	this->m_dimensions.x = w;
	this->m_dimensions.y = h;
}

void TransformComponent::setRotation(float r) {
	this->m_rotation = r;
}
