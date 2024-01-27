#pragma once

#include "game.h"
#include "fps.h"

struct GLFWwindow;

namespace aoe_engine {

	class ResourceManager;

	class Driver {

	public:
		static void run();
		static bool onInit();
		static void onUpdate();
		static void onRender();
		static void onCleanUp();

		static void onKeyEvent(GLFWwindow* window, int key, int scanCode, int action, int mods);

		static void setResourceLoaderCallback(bool (*callback)(ResourceManager*));
		static void setEntityLoaderCallback(bool (*callback)(Game*));

	private:
		static Game s_game;
		static GLFWwindow* s_window;

		static FPS s_fps;

		static bool initGL();
		static bool (*s_resource_loader_callback)(ResourceManager*);
		static bool (*s_entity_loader_callback)(Game*);
	};

}
