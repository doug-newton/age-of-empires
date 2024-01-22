#pragma once

#include "game.h"

struct GLFWwindow;

class Driver {

public:
	static void onInit();
	static void onUpdate(float delta);
	static void onRender();

	static void onKeyEvent(GLFWwindow* window, int key, int scanCode, int action, int mods);

private:
	static Game s_game;
};
