#pragma once

namespace aoe_engine {

	class Subject;
	class MotionSubject;
	class MovementSubject;
	class TransformSubject;
	class ViewSubject;
	class CameraInfoSubject;

	class Subscriber {

	public:
		Subscriber();
		virtual ~Subscriber();

		virtual void onMotionUpdate(const MotionSubject* subject);
		virtual void onMovementUpdate(const MovementSubject* subject);
		virtual void onTransformUpdate(const TransformSubject* subject);
		virtual void onViewUpdate(const ViewSubject* subject);
		virtual void onCameraInfoUpdate(const CameraInfoSubject* subject);

	protected:
		void subscribe(Subject* subject);

	};

}
