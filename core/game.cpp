#include "game.h"

Game::Game() :
	entities(0) {
}

Game::~Game() {
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		delete (*it);
	}
}

void Game::onInit() {
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		(*it)->onInit();
	}
}

void Game::onUpdate(float delta) {
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		(*it)->onUpdate(delta);
	}
}

void Game::onRender() {
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		(*it)->onRender();
	}
}

void Game::onKeyEvent(int key, int scanCode, int action, int mods) {
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		(*it)->onKeyEvent(key, scanCode, action, mods);
	}
}

void Game::addEntity(Entity* entity) {
	this->entities.push_back(entity);
}
