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

		void onChangeMotionMessage(ChangeMotionMessage* message) override;

	};

}
