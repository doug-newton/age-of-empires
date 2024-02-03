#pragma once

#include "../core/message.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class ChangeTransformMessage : public Message {

	public:
		ChangeTransformMessage(void* sender, const glm::vec2& translation_change, float rotation_change);
		virtual ~ChangeTransformMessage();

		virtual void accept(Component* component) override;

		glm::vec2 getVelocity();
		float getRotationalVelocity();

	private:
		
		glm::vec2 m_translation_change;
		float m_rotation_change;

	};

}
