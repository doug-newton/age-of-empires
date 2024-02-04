#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "wasd_component.h"
#include "../messages/change_motion_message.h"

namespace aoe_engine {

	WASDComponent::WASDComponent() :
		Component("WASD"),
		m_speed(0.5f) {
	}

	WASDComponent::~WASDComponent() {}

	void WASDComponent::onKeyEvent(int key, int scanCode, int action, int mods) {
		switch (action) {
		case GLFW_PRESS:
			switch (key) {
			case GLFW_KEY_W:
				goUp();
				break;
			case GLFW_KEY_A:
				goLeft();
				break;
			case GLFW_KEY_S:
				goDown();
				break;
			case GLFW_KEY_D:
				goRight();
				break;
			}
			break;
		case GLFW_RELEASE:
			stop();
			break;
		default:
			break;
		}
	}

	void WASDComponent::goUp() {
		ChangeMotionMessage* message = new ChangeMotionMessage(this);
		message->setNewVelocity(0, this->m_speed);
		sendMessage(message);
	}

	void WASDComponent::goDown() {
		ChangeMotionMessage* message = new ChangeMotionMessage(this);
		message->setNewVelocity(0, -this->m_speed);
		sendMessage(message);
	}

	void WASDComponent::goLeft() {
		ChangeMotionMessage* message = new ChangeMotionMessage(this);
		message->setNewVelocity(-this->m_speed, 0);
		sendMessage(message);
	}

	void WASDComponent::goRight() {
		ChangeMotionMessage* message = new ChangeMotionMessage(this);
		message->setNewVelocity(this->m_speed, 0);
		sendMessage(message);
	}

	void WASDComponent::stop() {
		sendMessage(new ChangeMotionMessage(this));
	}

}
