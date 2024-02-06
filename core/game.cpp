#include "game.h"
#include "entity.h"

namespace aoe_engine {

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

		success = success && m_resource_manager.onInit();

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

	void Game::onWindowResize(int width, int height) {
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->onWindowResize(width, height);
		}
	}

	void Game::onKeyEvent(int key, int scanCode, int action, int mods) {
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->onKeyEvent(key, scanCode, action, mods);
		}
	}

	void Game::onMouseButtonEvent(int button, int action, int mods, double x, double y) {
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->onMouseButtonEvent(button, action, mods, x, y);
		}
	}

	void Game::addEntity(Entity* entity) {
		entity->setGame(this);
		this->entities.push_back(entity);
	}

	ResourceManager* Game::getResourceManager() {
		return &this->m_resource_manager;
	}

}
