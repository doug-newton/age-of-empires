#pragma once

#include "../core/component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../core/message.h"
#include "../subjects/transform_subject.h"

namespace aoe_engine {

	class TransformComponent : public Component, public TransformSubject {

	public:

		TransformComponent();
		virtual ~TransformComponent();

		void onEntityRegistration() override;
		bool onInit() override;

		void onMotionUpdate(const MotionSubject* subject) override;

		void setTranslation(float x, float y);
		void setScaling(float x, float y);
	};

}
