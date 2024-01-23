#pragma once

#include "game.h"

struct GLFWwindow;
class ResourceManager;

class Driver {

public:
	static void run();
	static bool onInit();
	static void onUpdate(float delta);
	static void onRender();
	static void onCleanUp();

	static void onKeyEvent(GLFWwindow* window, int key, int scanCode, int action, int mods);

	static void setResourceLoaderCallback(bool (*callback)(ResourceManager*));

private:
	static Game s_game;
	static GLFWwindow* s_window;

	static bool initGL();
	static bool (*s_resource_loader_callback)(ResourceManager*);
	static bool (*s_entity_loader_callback)(Game*);
};
