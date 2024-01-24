#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "wasd_component.h"
#include "motion_component.h"

namespace aoe_engine {

	WASDComponent::WASDComponent() :
		Component("WASD"),
		m_speed(0.0005f),
		m_motion_component(nullptr) {
	}

	WASDComponent::~WASDComponent() {}

	bool WASDComponent::onInit() {
		void* p_motion_component = findComponent("motion");
		this->m_motion_component = static_cast<MotionComponent*>(p_motion_component);

		if (this->m_motion_component == nullptr) {
			return false;
		}

		return true;
	}

	void WASDComponent::onKeyEvent(int key, int scanCode, int action, int mods) {
		switch (action) {
		case GLFW_PRESS:
			switch (key) {
			case GLFW_KEY_A:
				this->m_motion_component->setVelocity(-this->m_speed, 0);
				break;
			case GLFW_KEY_D:
				this->m_motion_component->setVelocity(this->m_speed, 0);
				break;
			case GLFW_KEY_W:
				this->m_motion_component->setVelocity(0, this->m_speed);
				break;
			case GLFW_KEY_S:
				this->m_motion_component->setVelocity(0, -this->m_speed);
				break;
			}
			break;
		case GLFW_RELEASE:
			this->m_motion_component->setVelocity(0, 0);
			break;
		default:
			break;
		}
	}

}
