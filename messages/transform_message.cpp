#include "transform_message.h"
#include "../components/transform_component.h"

namespace aoe_engine {

	TransformMessage::TransformMessage(void* sender) :
		Message(sender) {
	}

	TransformMessage::~TransformMessage() {
	}

	void TransformMessage::visitTransformComponent(TransformComponent* component) {
	}

}
