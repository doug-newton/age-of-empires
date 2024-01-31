#pragma once

namespace aoe_engine {

	class AnimatedSpriteComponent;
	class CameraComponent;
	class MotionComponent;
	class QuadComponent;
	class SpriteComponent;
	class TransformComponent;
	class WASDComponent;

	class Message {

	public:
		Message(void* sender);
		void* getSender();
		virtual ~Message();

		virtual void visitAnimatedSpriteComponent(AnimatedSpriteComponent* component);
		virtual void visitCameraComponent(CameraComponent* component);
		virtual void visitMotionComponent(MotionComponent* component);
		virtual void visitQuadComponent(QuadComponent* component);
		virtual void visitSpriteComponent(SpriteComponent* component);
		virtual void visitTransformComponent(TransformComponent* component);
		virtual void visitWASDComponent(WASDComponent* component);

	private:
		void* m_sender;

	};

}
