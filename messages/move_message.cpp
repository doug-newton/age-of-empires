#include "move_message.h"
#include "../components/transform_component.h"

namespace aoe_engine {

	MoveMessage::MoveMessage(void* sender) :
		Message(sender) {
	}

	MoveMessage::~MoveMessage() {
	}

	void MoveMessage::visitTransformComponent(TransformComponent* component) {
	}

}
