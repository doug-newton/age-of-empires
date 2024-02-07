#include "motion_subject.h"

namespace aoe_engine {

	MotionSubject::MotionSubject(const std::string& name) :
		Subject(name),
		velocity_x(0.0f), 
		velocity_y(0.0f) {
	}

	MotionSubject::~MotionSubject() {
	}

	void MotionSubject::notify(Subscriber* subscriber) {
		subscriber->onMotionUpdate(this);
	}

}