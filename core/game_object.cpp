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
}