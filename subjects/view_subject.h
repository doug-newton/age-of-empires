#pragma once

#include "../core/subject.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class Entity;

	class ViewSubject : public Subject {

	public:
		ViewSubject();
		virtual ~ViewSubject();

		void notify(Subscriber* subscriber) override;

		Entity* camera;
		glm::vec2 translation;
		glm::vec2 scaling;
		float aspect_ratio;

	};

}
