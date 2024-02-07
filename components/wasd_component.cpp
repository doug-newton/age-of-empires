#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "wasd_component.h"
#include "../core/entity.h"

namespace aoe_engine {

	WASDComponent::WASDComponent() :
		Component("WASD"),
		MovementSubject(),
		m_speed(0.5f) {
	}

	WASDComponent::~WASDComponent() {}

	void WASDComponent::onEntityRegistration() {
		registerSubject(this->getParent());
	}

	void WASDComponent::onKeyEvent(int key, int scanCode, int action, int mods) {
		switch (action) {
		case GLFW_PRESS:
			switch (key) {
			case GLFW_KEY_W:
				moving_up = true;
				break;
			case GLFW_KEY_A:
				moving_left = true;
				break;
			case GLFW_KEY_S:
				moving_down = true;
				break;
			case GLFW_KEY_D:
				moving_right = true;
				break;
			}
			break;
		case GLFW_RELEASE:
			switch (key) {
			case GLFW_KEY_W:
				moving_up = false;
				break;
			case GLFW_KEY_A:
				moving_left = false;
				break;
			case GLFW_KEY_S:
				moving_down = false;
				break;
			case GLFW_KEY_D:
				moving_right = false;
				break;
			}
			break;
		default:
			break;
		}

		publish();
	}

}
