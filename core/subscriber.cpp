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
	void Subscriber::onMovementUpdate(const MovementSubject* subject) {}
	void Subscriber::onTransformUpdate(const TransformSubject* subject) {}
	void Subscriber::onViewUpdate(const ViewSubject* subject) {}
	void Subscriber::onCameraInfoUpdate(const CameraInfoSubject* subject) {}
	void Subscriber::onClickUpdate(const ClickSubject* subject) {}
	void Subscriber::onSelectionUpdate(const SelectionSubject* subject) {}
	void Subscriber::onSetTransformUpdate(const SetTransformSubject* subject) {}

}
