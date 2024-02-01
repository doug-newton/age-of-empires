#pragma once

#include "../core/message.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class TransformMessage : public Message {

	public:
		TransformMessage(void* sender, const glm::vec2& velocity, float r_velocity);
		virtual ~TransformMessage();

		void visitTransformComponent(TransformComponent* transform_component);

	private:
		
		glm::vec2 m_velocity;
		float m_rotational_velocity;

	};

}
