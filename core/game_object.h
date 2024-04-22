#pragma once

#include "../events/mouse_button_event.h"
#include "../events/mouse_move_event.h"

namespace aoe_engine {

	class Game;

	class GameObject {

	public:

		GameObject();
		virtual ~GameObject() = 0;
		virtual bool onInit() = 0;
		virtual void onUpdate(float delta) = 0;
		virtual void onRender() = 0;

		virtual void onWindowResize(int width, int height) = 0;
		virtual void onKeyEvent(int key, int scanCode, int action, int mods) = 0;
		virtual void onMouseButtonEvent(const MouseButtonEvent& event) = 0;
		virtual void onMouseMoveEvent(const MouseMoveEvent& event) = 0;

		void setGame(Game* game);
		Game* getGame();

	protected:

		Game* m_game;

	};
}
