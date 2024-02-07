#include "game.h"
#include "entity.h"
#include <stdexcept>
#include "message.h"

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

	void Entity::onMouseButtonEvent(const MouseButtonEvent& event) {
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			(*it).second->onMouseButtonEvent(event);
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

	void Entity::sendMessage(Message* message) {
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			Component* component = (*it).second;
			if (message->getSender() == component) {
				continue;
			}
			message->accept(component);
		}
		delete message;
	}

	void Entity::registerSubject(const std::string& name, Subject* subject) {
		if (this->m_subjects.find(name) != this->m_subjects.end()) {
			return;
		}

		this->m_subjects[name] = subject;
	}

	Subject* Entity::getSubject(const std::string& name) {
		auto result = this->m_subjects.find(name);

		if (result == this->m_subjects.end()) {
			return nullptr;
		}

		return (*result).second;
	}

}