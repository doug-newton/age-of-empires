#include "transform_message.h"
#include "../components/transform_component.h"

/*
	instead of messages being visitors, would make more sense for messages 
	to accept components and for components to visit messages, i.e. base component
	could have virtual 'onTransformMessage()', 'onModelMatrixMessage()', etc, and choose
	whether or not to interact with / listen to these messages as required

	too much TransformationComponent logic in the TransformMessage
	- this logic should stay in the TransformComponent
*/

namespace aoe_engine {

	TransformMessage::TransformMessage(void* sender, const glm::vec2& velocity, float r_velocity) :
		Message(sender),
		m_velocity(velocity),
		m_rotational_velocity(r_velocity) {
	}

	TransformMessage::~TransformMessage() {
	}

	void TransformMessage::accept(Component* component) {
		component->onTransformMessage(this);
	}

	glm::vec2 TransformMessage::getVelocity() {
		return this->m_velocity;
	}

	float TransformMessage::getRotationalVelocity() {
		return this->m_rotational_velocity;
	}

}
