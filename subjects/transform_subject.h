#pragma once

#include "../core/subject.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class TransformSubject : public Subject {

	public:

		TransformSubject();
		virtual ~TransformSubject();

		void notify(Subscriber* subscriber);

		glm::vec2 translation;
		glm::vec2 scaling;
		float rotation;

	};

}
