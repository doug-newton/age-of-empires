#include "camera_info_relay.h"
#include "../subjects/view_subject.h"
#include "camera_system.h"

namespace aoe_engine {

	CameraInfoRelay::CameraInfoRelay() {
	}

	CameraInfoRelay::~CameraInfoRelay() {
	}

	void CameraInfoRelay::subscribe(Camera* camera) {
		Subject* view_subject = camera->getSubject("view");
		view_subject->addSubscriber(this);
	}

	void CameraInfoRelay::onViewUpdate(const ViewSubject* subject) {
		if (subject->camera != CameraSystem::getActiveCamera()) {
			return;
		}

		this->position = subject->translation;
		this->scaling = subject->scaling;
		this->aspect_ratio = subject->aspect_ratio;

		publish();
	}

	void CameraInfoRelay::notify(Subscriber* subscriber) {
		subscriber->onCameraInfoUpdate(this);
	}

}
