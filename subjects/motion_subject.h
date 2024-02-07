#pragma once

#include "../core/subject.h"

namespace aoe_engine {

	class MotionSubject : public Subject {
	public:
		MotionSubject(const std::string& name);
		virtual ~MotionSubject();

		void notify(Subscriber* subscriber);

		float velocity_x;
		float velocity_y;
	};

}
