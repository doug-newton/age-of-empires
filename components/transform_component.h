#pragma once

#include "../core/component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TransformComponent : public Component {

public:

	TransformComponent();
	virtual ~TransformComponent();

	const glm::vec2& getPosition();
	const glm::vec2& getDimensions();
	float getRotation();

	void setPosition(float x, float y);
	void setDimensions(float w, float h);
	void setRotation(float r);

private:

	glm::vec2 m_position;
	glm::vec2 m_dimensions;

	float m_rotation;
};
