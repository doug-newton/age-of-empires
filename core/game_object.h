#pragma once

#include "../events/mouse_button_event.h"
#include "../events/mouse_move_event.h"

namespace aoe_engine {

	class Game;

	class GameObject {

	public:

		GameObject();
		virtual ~GameObject();
		virtual bool onInit();
		virtual void onUpdate(float delta);
		virtual void onRender();

		virtual void onWindowResize(int width, int height);
		virtual void onKeyEvent(int key, int scanCode, int action, int mods);
		virtual void onMouseButtonEvent(const MouseButtonEvent& event);
		virtual void onMouseMoveEvent(const MouseMoveEvent& event);

		void setGame(Game* game);
		Game* getGame();

	protected:

		Game* m_game;

	};
}
