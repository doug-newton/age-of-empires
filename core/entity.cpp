#include "game.h"
#include "entity.h"
#include <stdexcept>

namespace aoe_engine {

	Entity::Entity() :
		m_game(nullptr) {
	}

	Entity::~Entity() {
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			delete (*it).second;
		}
	}

	bool Entity::onInit() {
		bool success = true;
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			success = success && (*it).second->onInit();
		}
		return success;
	}

	void Entity::onUpdate(float delta) {
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			(*it).second->onUpdate(delta);
		}
	}

	void Entity::onRender() {
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			(*it).second->onRender();
		}
	}

	void Entity::onWindowResize(int width, int height) {
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			(*it).second->onWindowResize(width, height);
		}
	}

	void Entity::onKeyEvent(int key, int scanCode, int action, int mods) {
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			(*it).second->onKeyEvent(key, scanCode, action, mods);
		}
	}

	void Entity::registerComponent(Component* component) {
		const std::string& c_name = component->getName();

		if (m_components.find(c_name) != m_components.end()) {
			throw new component_exists_exception();
		}

		this->m_components[c_name] = component;
		component->setParent(this);
	}

	Component* Entity::findComponent(const std::string& name) {
		auto result = m_components.find(name);

		if (result == m_components.end()) {
			return nullptr;
		}

		return (*result).second;
	}

	void Entity::setGame(Game* game) {
		this->m_game = game;
	}

	Game* Entity::getGame() {
		return this->m_game;
	}

}