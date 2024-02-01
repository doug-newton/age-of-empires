#pragma once

#include "../core/message.h"

namespace aoe_engine {

	class TransformMessage : public Message {

	public:
		TransformMessage(void* sender);
		virtual ~TransformMessage();

		void visitTransformComponent(TransformComponent* transform_component);

	};

}
