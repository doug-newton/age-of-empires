#pragma once

#include <vector>
#include "resource_manager.h"

namespace aoe_engine {

	class Entity;

	class Game {

	public:
		Game();
		~Game();

		bool onInit();
		void onUpdate(float delta);
		void onRender();

		void onWindowResize(int width, int height);
		void onKeyEvent(int key, int scanCode, int action, int mods);
		void onMouseButtonEvent(int button, int action, int mods);

		void addEntity(Entity* entity);

		ResourceManager* getResourceManager();

	private:
		std::vector<Entity*> entities;
		ResourceManager m_resource_manager;
	};

}
