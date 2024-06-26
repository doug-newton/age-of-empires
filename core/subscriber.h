#pragma once

namespace aoe_engine {

	class Subject;
	class MotionSubject;
	class MovementSubject;
	class TransformSubject;
	class ViewSubject;
	class CameraInfoSubject;
	class ClickSubject;
	class SelectionSubject;
	class SetTransformSubject;
	class CardinalMovementSubject;

	class Subscriber {

	public:
		Subscriber();
		virtual ~Subscriber();

		virtual void onMotionUpdate(const MotionSubject* subject);
		virtual void onMovementUpdate(const MovementSubject* subject);
		virtual void onTransformUpdate(const TransformSubject* subject);
		virtual void onViewUpdate(const ViewSubject* subject);
		virtual void onCameraInfoUpdate(const CameraInfoSubject* subject);
		virtual void onClickUpdate(const ClickSubject* subject);
		virtual void onSelectionUpdate(const SelectionSubject* subject);
		virtual void onSetTransformUpdate(const SetTransformSubject* subject);
		virtual void onCardinalMovementUpdate(const CardinalMovementSubject* subject);

	protected:
		void subscribe(Subject* subject);

	};

}
