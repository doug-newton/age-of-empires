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
		bool onInit();
		void onUpdate(float delta);
		void onRender();

		void onWindowResize(int width, int height);
		void onKeyEvent(int key, int scanCode, int action, int mods);

		void registerComponent(Component* component);
		Component* findComponent(const std::string& name);
		void setGame(Game* game);
		Game* getGame();

	private:

		Game* m_game;
		std::map<std::string, Component*> m_components;


	};

}