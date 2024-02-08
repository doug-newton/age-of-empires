#include "camera_system.h"

namespace aoe_engine {

	Camera* CameraSystem::getActiveCamera() {
		return s_active_camera;
	}

	void CameraSystem::registerCamera(Camera* camera) {
		s_camera_info_relay.subscribe(camera);
	}

	void CameraSystem::addCameraInfoSubscriber(Subscriber* subscriber) {
		s_camera_info_relay.addSubscriber(subscriber);
	}

	Camera* CameraSystem::s_active_camera(nullptr);
	CameraInfoRelay CameraSystem::s_camera_info_relay;

}
