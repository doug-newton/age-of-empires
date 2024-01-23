#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "driver.h"
#include "resource_manager.h"

void Driver::run() {
	while (!glfwWindowShouldClose(s_window)) {
		glfwPollEvents();
		onUpdate(1.0);
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

	return true;
}

void Driver::onUpdate(float delta) {
	s_game.onUpdate(delta);
}

void Driver::onRender() {
	s_game.onRender();
}

void Driver::onKeyEvent(GLFWwindow* window, int key, int scanCode, int action, int mods) {
	s_game.onKeyEvent(key, scanCode, action, mods);
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

	int width = 1280;
	int height = 960;

	s_window = glfwCreateWindow(width, height, "Age of Empires", NULL, NULL);
	if (s_window == nullptr) {
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(s_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return false;
	}

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glfwSetKeyCallback(s_window, onKeyEvent);

	return true;
}

Game Driver::s_game;
GLFWwindow* Driver::s_window = nullptr;
bool (*Driver::s_resource_loader_callback)(ResourceManager*) = nullptr;
bool (*Driver::s_entity_loader_callback)(Game*) = nullptr;