#include "fps.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace aoe_engine {

	FPS::FPS() :
		delta(0.0f),
		lastTime(0.0f) {
		this->lastTime = glfwGetTime();
	}

	float FPS::getDelta() {
		return this->delta;
	}

	void FPS::calcDelta() {
		float currentTime = glfwGetTime();
		delta = currentTime - lastTime;
		lastTime = currentTime;
	}

}