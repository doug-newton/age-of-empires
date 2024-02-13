#pragma once

#include "game.h"
#include "fps.h"
#include "../events/mouse_button_event.h"
#include "../events/mouse_move_event.h"

struct GLFWwindow;

namespace aoe_engine {

	class ResourceManager;

	class Driver {

	public:

		static void setWindowDetails(const std::string& window_title, int width, int height);

		static void run();

		static bool onInit();
		static void onUpdate();
		static void onRender();
		static void onCleanUp();

		static void onWindowResize(GLFWwindow* window, int width, int height);
		static void onKeyEvent(GLFWwindow* window, int key, int scanCode, int action, int mods);
		static void onMouseButtonEvent(GLFWwindow* window, int button, int action, int mods);
		static void onMouseMove(GLFWwindow* window, double x, double y);

		static void setResourceLoaderCallback(bool (*callback)(ResourceManager*));
		static void setEntityLoaderCallback(bool (*callback)(Game*));

	private:
		static Game s_game;
		static GLFWwindow* s_window;
		static std::string s_window_title;
		static int s_window_width;
		static int s_window_height;

		static FPS s_fps;

		static bool initGL();
		static bool (*s_resource_loader_callback)(ResourceManager*);
		static bool (*s_entity_loader_callback)(Game*);
	};

}
