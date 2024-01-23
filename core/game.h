#pragma once

#include <vector>
#include "entity.h"
#include "resource_manager.h"

class Game {

public:
	Game();
	~Game();
	bool onInit();
	void onUpdate(float delta);
	void onRender();
	void onKeyEvent(int key, int scanCode, int action, int mods);

	void addEntity(Entity* entity);

	ResourceManager* getResourceManager();

private:
	std::vector<Entity*> entities;
	ResourceManager m_resource_manager;
};
