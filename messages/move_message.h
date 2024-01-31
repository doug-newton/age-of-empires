#pragma once

#include "../core/message.h"

namespace aoe_engine {

	class TransformComponent;

	class MoveMessage : public Message {

	public:
		MoveMessage(void* sender);
		virtual ~MoveMessage();

		void visitTransformComponent(TransformComponent* transform_component);

	};

}
