#include "camera_info_subject.h"

namespace aoe_engine {

	CameraInfoSubject::CameraInfoSubject() :
		Subject("camera_info"),
		position(0.0f, 0.0f),
		scaling(1.0f, 1.0f),
		aspect_ratio(1.0f) {
	}

	CameraInfoSubject::~CameraInfoSubject() {
	}

	void CameraInfoSubject::notify(Subscriber* subscriber) {
	}

}
