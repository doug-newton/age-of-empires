#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "driver.h"

void Driver::onInit() {
	s_game.onInit();
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

Game Driver::s_game;