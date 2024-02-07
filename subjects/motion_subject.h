#pragma once

#include "../core/subject.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class MotionSubject : public Subject {
	public:
		MotionSubject(const std::string& name);
		virtual ~MotionSubject();

		void notify(Subscriber* subscriber);

		float delta;
		glm::vec2 velocity;
	};

}
