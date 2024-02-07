#include "motion_subject.h"

namespace aoe_engine {

	MotionSubject::MotionSubject(const std::string& name) :
		Subject(name),
		delta(0.0f),
		velocity(0.0f, 0.0f) 
	{
	}

	MotionSubject::~MotionSubject() {
	}

	void MotionSubject::notify(Subscriber* subscriber) {
		subscriber->onMotionUpdate(this);
	}

}