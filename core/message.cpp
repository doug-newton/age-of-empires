#include "message.h"
#include "component.h"

namespace aoe_engine {

	Message::Message(void* sender) :
		m_sender(sender) {
	}

	Message::~Message() {
	}

	void* Message::getSender() {
		return this->m_sender;
	}

	void Message::visitAnimatedSpriteComponent(AnimatedSpriteComponent* component) {}
	void Message::visitCameraComponent(CameraComponent* component) {}
	void Message::visitMotionComponent(MotionComponent* component) {}
	void Message::visitQuadComponent(QuadComponent* component) {}
	void Message::visitSpriteComponent(SpriteComponent* component) {}
	void Message::visitTransformComponent(TransformComponent* component) {}
	void Message::visitWASDComponent(WASDComponent* component) {}
}