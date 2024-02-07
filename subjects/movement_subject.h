#pragma once

#include "../core/subject.h"

namespace aoe_engine {

	class MovementSubject : public Subject {

	public:

		MovementSubject();
		virtual ~MovementSubject();

		void notify(Subscriber* subscriber) override;

		bool moving_left;
		bool moving_right;
		bool moving_up;
		bool moving_down;

	};

}
