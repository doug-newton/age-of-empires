#pragma once

namespace aoe_engine {

	class Subject;
	class MotionSubject;

	class Subscriber {

	public:
		Subscriber();
		virtual ~Subscriber();

		virtual void onMotionUpdate(const MotionSubject* subject);

	protected:
		void subscribe(Subject* subject);

	};

}
