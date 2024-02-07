#include "component.h"
#include "game.h"
#include "entity.h"
#include <type_traits>
#include "message.h"
#include "subject.h"

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

	void Component::onWindowResize(int width, int height) {
	}

	void Component::onKeyEvent(int key, int scancode, int action, int mods) {
	}

	void Component::onMouseButtonEvent(const MouseButtonEvent& event) {
	}

	const std::string& Component::getName() {
		return this->m_name;
	}

	void Component::setParent(Entity* parent) {
		this->m_parent = parent;
		onSetParent();
	}

	void Component::onSetParent() { }

	void Component::subscribe(const std::string& name) {
		Subject* subject = this->m_parent->getSubject(name);
		if (subject == nullptr) {
			return;
		}
		subject->addSubscriber(this);
	}

	void Component::onChangeMotionMessage(ChangeMotionMessage* message) {}

	ShaderProgram* Component::getShaderProgram(const std::string& name) {
		ResourceManager* mgr = getResourceManager();

		if (mgr == nullptr) {
			return nullptr;
		}

		return mgr->getShaderProgram(name);
	}

	Vao* Component::getVao(const std::string& name) {
		ResourceManager* mgr = getResourceManager();

		if (mgr == nullptr) {
			return nullptr;
		}

		return mgr->getVao(name);
	}

	Texture* Component::getTexture(const std::string& name) {
		ResourceManager* mgr = getResourceManager();

		if (mgr == nullptr) {
			return nullptr;
		}

		return mgr->getTexture(name);
	}

	void Component::sendMessage(Message* message) {
		this->m_parent->sendMessage(message);
	}

	Entity* Component::getParent() {
		return this->m_parent;
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