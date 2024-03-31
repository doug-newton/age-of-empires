#include "cardinal_movement_subject.h"
#include "../core/subscriber.h"

namespace aoe_engine {

	CardinalMovementSubject::CardinalMovementSubject() :
		Subject("cardinal_movement"),
		moving_left(false),
		moving_right(false),
		moving_up(false),
		moving_down(false) {
	}

	CardinalMovementSubject::~CardinalMovementSubject() {
	}

	void CardinalMovementSubject::notify(Subscriber* subscriber) {
		subscriber->onCardinalMovementUpdate(this);
	}

}
