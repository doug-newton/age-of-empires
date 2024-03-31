#include "movement_subject.h"
#include "../core/subscriber.h"

namespace aoe_engine {

	MovementSubject::MovementSubject() :
		Subject("movement"),
		moving_left(false),
		moving_right(false),
		moving_up(false),
		moving_down(false),
		moving(false),
		direction(0.0f) {
	}

	MovementSubject::~MovementSubject() {
	}

	void MovementSubject::notify(Subscriber* subscriber) {
		subscriber->onMovementUpdate(this);
	}

}