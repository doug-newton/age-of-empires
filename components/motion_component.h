#pragma once

#include "../core/component.h"
#include <glm/glm.hpp>

class TransformComponent;

class MotionComponent : public Component {
public:

	MotionComponent();
	virtual ~MotionComponent();

	void setVelocity(float x, float y);
	void setRotationalVelocity(float r);

	virtual bool onInit();
	virtual void onUpdate(float delta);

private:

	glm::vec2 m_velocity;
	float m_rotational_velocity;
	TransformComponent* m_transform_component;

};
