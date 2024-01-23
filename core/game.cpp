#include "game.h"
#include "entity.h"

Game::Game() :
	entities(0) {
}

Game::~Game() {
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		delete (*it);
	}
}

bool Game::onInit() {
	bool success = true;
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		success = success && (*it)->onInit();
	}
	return success;
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
	entity->setGame(this);
	this->entities.push_back(entity);
}

ResourceManager* Game::getResourceManager() {
	return &this->m_resource_manager;
}
