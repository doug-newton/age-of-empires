#pragma once

#include <map>
#include <string>

#include "component.h"
#include "component_exists_exception.h"

namespace aoe_engine {

	class Game;

	class Entity {
	public:

		Entity();
		~Entity();
		virtual bool onInit();
		virtual void onUpdate(float delta);
		virtual void onRender();

		virtual void onWindowResize(int width, int height);
		virtual void onKeyEvent(int key, int scanCode, int action, int mods);
		virtual void onMouseButtonEvent(int button, int action, int mods, double x, double y);

		void registerComponent(Component* component);
		Component* findComponent(const std::string& name);
		void setGame(Game* game);
		Game* getGame();

		void sendMessage(Message*);

	private:

		Game* m_game;
		std::map<std::string, Component*> m_components;


	};

}