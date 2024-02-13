#pragma once

#include "../core/subject.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class SetTransformSubject: public Subject {

	public:

		SetTransformSubject();
		~SetTransformSubject();

		void notify(Subscriber* subscriber);

		glm::vec2 translation;
		glm::vec2 scaling;

	};

}
