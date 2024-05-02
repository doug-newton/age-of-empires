#include "game_object.h"
#include "game.h"

namespace aoe_engine {

	GameObject::GameObject() :
		m_game(nullptr) {
	}

	GameObject::~GameObject() {}

	void GameObject::setGame(Game* game) {
		this->m_game = game;
	}

	Game* GameObject::getGame() {
		return this->m_game;
	}

	bool GameObject::onInit() { return true; }
	void GameObject::onUpdate(float delta) {}
	void GameObject::onRender() {}
	void GameObject::onWindowResize(int width, int height) {}
	void GameObject::onKeyEvent(int key, int scanCode, int action, int mods) {}
	void GameObject::onMouseButtonEvent(const MouseButtonEvent& event) {}
	void GameObject::onMouseMoveEvent(const MouseMoveEvent& event) {}
}