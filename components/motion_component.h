#pragma once

#include "../core/component.h"
#include <glm/glm.hpp>
#include "../subjects/motion_subject.h"

namespace aoe_engine {

	class MotionComponent : public Component, public MotionSubject {
	public:

		MotionComponent();
		virtual ~MotionComponent();

		void onUpdate(float delta) override;
		void onSetParent() override;

		void setVelocity(float x, float y);
		void setRotationalVelocity(float r);

		void onChangeMotionMessage(ChangeMotionMessage* message) override;

	private:

		glm::vec2 m_velocity;
		glm::vec2 m_scaling_velocity;
		float m_rotational_velocity;

	};

}
