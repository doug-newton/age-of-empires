#pragma once

#include "../core/component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace aoe_engine {

	class TransformComponent : public Component {

	public:

		TransformComponent();
		virtual ~TransformComponent();

		const glm::vec2& getTranslation();
		const glm::vec2& getScaling();
		float getRotation();

		void setTranslation(float x, float y);
		void setScaling(float w, float h);
		void setRotation(float r);

	private:

		glm::vec2 m_translation;
		glm::vec2 m_scaling;

		float m_rotation;
	};

}
