#include "subscriber.h"
#include "subject.h"

namespace aoe_engine {

	Subscriber::Subscriber() {
	}

	Subscriber::~Subscriber() {
	}

	void Subscriber::subscribe(Subject* subject) {
		subject->addSubscriber(this);
	}

	void Subscriber::onMotionUpdate(const MotionSubject* subject) {}

}
