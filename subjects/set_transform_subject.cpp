#include "set_transform_subject.h"

namespace aoe_engine {

	SetTransformSubject::SetTransformSubject() :
		Subject("set_transform"),
		translation(0.0f, 0.0f),
		scaling(1.0f, 1.0f) {
	}

	SetTransformSubject::~SetTransformSubject() {
	}

	void SetTransformSubject::notify(Subscriber* subscriber) {
		subscriber->onSetTransformUpdate(this);
	}

}
