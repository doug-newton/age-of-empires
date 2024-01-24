#include "component.h"
#include "game.h"
#include "entity.h"

namespace aoe_engine {

	Component::Component(const std::string& name) :
		m_parent(nullptr),
		m_name(name)
	{
	}

	Component::~Component() {
	}

	bool Component::onInit() {
		return true;
	}

	void Component::onUpdate(float delta) {
	}

	void Component::onRender() {
	}

	void Component::onKeyEvent(int key, int scancode, int action, int mods) {
	}

	const std::string& Component::getName() {
		return this->m_name;
	}

	void Component::setParent(Entity* parent) {
		this->m_parent = parent;
	}

	ResourceManager* Component::getResourceManager() {
		if (this->m_parent == nullptr) {
			return nullptr;
		}

		if (this->m_parent->getGame() == nullptr) {
			return nullptr;
		}

		return this->m_parent->getGame()->getResourceManager();
	}

	Component* Component::findComponent(const std::string& name) {
		return this->m_parent->findComponent(name);
	}

}