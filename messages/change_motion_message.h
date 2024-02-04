#pragma once

#include "../core/message.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class ChangeMotionMessage : public Message {

	public:

		ChangeMotionMessage(Component* sender);
		virtual ~ChangeMotionMessage();

		void accept(Component* component) override;

		void setNewVelocity(float x, float y);
		glm::vec2 getNewVelocity();

	private:

		glm::vec2 m_new_velocity;

	};

}
