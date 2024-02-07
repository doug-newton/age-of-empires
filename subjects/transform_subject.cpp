#include "transform_subject.h"

namespace aoe_engine {

	TransformSubject::TransformSubject() :
		Subject("transform"),
		translation(0.0f, 0.0f),
		scaling(1.0f, 1.0f),
		rotation(0.0f) {
	}

	TransformSubject::~TransformSubject() {
	}

	void TransformSubject::notify(Subscriber* subscriber) {
		subscriber->onTransformUpdate(this);
	}


}