#pragma once

#include "../core/subject.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class CameraInfoSubject: public Subject {

	public:

		CameraInfoSubject();
		virtual ~CameraInfoSubject();

		void notify(Subscriber* subscriber);

		glm::vec2 position;
		glm::vec2 scaling;
		float aspect_ratio;

	};

}
