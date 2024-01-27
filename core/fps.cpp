#include "fps.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace aoe_engine {

	FPS::FPS() :
		m_delta(0.0f),
		m_last_time(0.0f) {
		this->m_last_time = glfwGetTime();
	}

	float FPS::getDelta() {
		return this->m_delta;
	}

	void FPS::calcDelta() {
		float current_time = glfwGetTime();
		m_delta = current_time - m_last_time;
		m_last_time = current_time;
	}

}