#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "driver.h"
#include "resource_manager.h"

namespace aoe_engine {

	void Driver::setWindowDetails(const std::string& title, int width, int height) {
		s_window_title = title;
		s_window_width = width;
		s_window_height = height;
	}

	void Driver::run() {
		while (!glfwWindowShouldClose(s_window)) {
			glClear(GL_COLOR_BUFFER_BIT);
			glfwPollEvents();
			onUpdate();
			onRender();
			glfwSwapBuffers(s_window);
		}
	}

	bool Driver::onInit() {
		if (!initGL()) {
			return false;
		}

		if (s_resource_loader_callback != nullptr) {
			if (!s_resource_loader_callback(s_game.getResourceManager())) {
				return false;
			}
		}

		if (s_entity_loader_callback != nullptr) {
			if (!s_entity_loader_callback(&s_game)) {
				return false;
			}
		}

		if (!s_game.onInit()) {
			return false;
		}

		s_game.onWindowResize(s_window_width, s_window_height);

		return true;
	}

	void Driver::onUpdate() {
		s_fps.calcDelta();
		float delta = s_fps.getDelta();
		s_game.onUpdate(delta);
	}

	void Driver::onRender() {
		s_game.onRender();
	}

	void Driver::onWindowResize(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
		s_window_width = width;
		s_window_height = height;
		s_game.onWindowResize(width, height);
	}

	void Driver::onKeyEvent(GLFWwindow* window, int key, int scanCode, int action, int mods) {
		s_game.onKeyEvent(key, scanCode, action, mods);
	}

	void Driver::onMouseButtonEvent(GLFWwindow* window, int button, int action, int mods) {
		double x, y;
		glfwGetCursorPos(s_window, &x, &y);
		MouseButtonEvent event;

		event.button = button;
		event.action = action;
		event.mods = mods;
		event.x = x;
		event.y = y;
		event.screen_width = s_window_width;
		event.screen_height = s_window_height;

		s_game.onMouseButtonEvent(event);
	}

	void Driver::onMouseMove(GLFWwindow* window, double x, double y) {
		MouseMoveEvent event;

		event.x = x;
		event.y = y;
		event.screen_width = s_window_width;
		event.screen_height = s_window_height;

		s_game.onMouseMoveEvent(event);
	}

	void Driver::onCleanUp() {
		glfwTerminate();
	}

	void Driver::setEntityLoaderCallback(bool (*callback)(Game*)) {
		s_entity_loader_callback = callback;
	}

	void Driver::setResourceLoaderCallback(bool (*callback)(ResourceManager*)) {
		s_resource_loader_callback = callback;
	}

	bool Driver::initGL() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		s_window = glfwCreateWindow(s_window_width, s_window_height, s_window_title.c_str(), NULL, NULL);
		if (s_window == nullptr) {
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(s_window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			return false;
		}

		glViewport(0, 0, s_window_width, s_window_height);

		glfwSetFramebufferSizeCallback(s_window, onWindowResize);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glfwSetKeyCallback(s_window, onKeyEvent);
		glfwSetMouseButtonCallback(s_window, onMouseButtonEvent);
		glfwSetCursorPosCallback(s_window, onMouseMove);

		return true;
	}

	Game Driver::s_game;
	GLFWwindow* Driver::s_window = nullptr;
	FPS Driver::s_fps;
	bool (*Driver::s_resource_loader_callback)(ResourceManager*) = nullptr;
	bool (*Driver::s_entity_loader_callback)(Game*) = nullptr;

	std::string Driver::s_window_title = "Unnamed Window";
	int Driver::s_window_width = 1280;
	int Driver::s_window_height = 960;
}