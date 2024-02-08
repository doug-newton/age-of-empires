#pragma once

#include "../core/subscriber.h"
#include "../camera/camera.h"
#include "../subjects/camera_info_subject.h"

/*
	subscribes to the ViewSubject of every Camera instance.
	when an update is received from the active camera, it publishes 
	itself as a CameraInfoSubject.
*/

namespace aoe_engine {

	class CameraInfoRelay: public CameraInfoSubject, public Subscriber {

	public:

		CameraInfoRelay();
		virtual ~CameraInfoRelay();

		void subscribe(Camera* camera);
		void onViewUpdate(const ViewSubject* viewSubject) override;
		void notify(Subscriber* subscriber);

	};

}
