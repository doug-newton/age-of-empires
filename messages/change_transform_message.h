#pragma once

#include "../core/message.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class ChangeTransformMessage : public Message {

	public:
		ChangeTransformMessage(void* sender, const glm::vec2& velocity, float r_velocity);
		virtual ~ChangeTransformMessage();

		virtual void accept(Component* component) override;

		glm::vec2 getVelocity();
		float getRotationalVelocity();

	private:
		
		glm::vec2 m_velocity;
		float m_rotational_velocity;

	};

}
