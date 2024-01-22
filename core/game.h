#pragma once

#include <vector>
#include "entity.h"

class Game {

public:
	Game();
	~Game();
	void onInit();
	void onUpdate(float delta);
	void onRender();
	void onKeyEvent(int key, int scanCode, int action, int mods);

	void addEntity(Entity* entity);

private:
	std::vector<Entity*> entities;
};
