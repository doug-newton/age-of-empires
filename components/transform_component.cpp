#include "transform_component.h"
#include "../subjects/motion_subject.h"
#include "../core/entity.h"

namespace aoe_engine {

	TransformComponent::TransformComponent() :
		Component("transform"),
		TransformSubject()
	{
	}

	TransformComponent::~TransformComponent() {
	}

	void TransformComponent::onEntityRegistration() {
		this->registerSubject(this->getParent());
	}

	bool TransformComponent::onInit() {
		subscribe("motion");
		return true;
	}

	void TransformComponent::onMotionUpdate(const MotionSubject* subject) {
		this->translation.x += subject->velocity.x * subject->delta;
		this->translation.y += subject->velocity.y * subject->delta;
		publish();
	}

	void TransformComponent::setScaling(float x, float y) {
		this->scaling.x = x;
		this->scaling.y = y;
		publish();
	}

	void TransformComponent::setTranslation(float x, float y) {
		this->translation.x = x;
		this->translation.y = y;
		publish();
	}

}
