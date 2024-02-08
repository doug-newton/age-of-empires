#pragma once
#include "camera.h"
#include "camera_info_relay.h"

namespace aoe_engine {

	class CameraSystem {

		friend class Camera;

	public:

		static Camera* getActiveCamera();
		static void registerCamera(Camera* camera);
		static void addCameraInfoSubscriber(Subscriber* subscriber);

	private:

		static Camera* s_active_camera;
		static CameraInfoRelay s_camera_info_relay;

	};

}
