#include "view_subject.h"

namespace aoe_engine {

	ViewSubject::ViewSubject() :
		Subject("view"),
		camera(nullptr),
		translation(0.0f, 0.0f),
		scaling(1.0f, 1.0f),
		aspect_ratio(1.0f) {
	}

	ViewSubject::~ViewSubject() {
	}

	void ViewSubject::notify(Subscriber* subscriber) {
		subscriber->onViewUpdate(this);
	}

}
