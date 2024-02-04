#pragma once

#include "../core/message.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class ChangeTransformMessage : public Message {

	public:

		ChangeTransformMessage(void* sender);

		ChangeTransformMessage(
			void* sender, 
			const glm::vec2& translation_change, 
			const glm::vec2& scaling_change, 
			float rotation_change);

		virtual ~ChangeTransformMessage();

		virtual void accept(Component* component) override;

		glm::vec2 getTranslationChange();
		glm::vec2 getScalingChange();
		float getRotationChange();

		void setTranslationChange(float x, float y);
		void setScalingChange(float x, float y);
		void setRotationChange(float r);

	private:
		
		glm::vec2 m_translation_change;
		glm::vec2 m_scaling_change;
		float m_rotation_change;

	};

}
