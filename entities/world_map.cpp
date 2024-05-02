#include "world_map.h"
#include "../core/game.h"
#include "../core/resource_manager.h"

namespace aoe_engine {

	WorldMap::WorldMap(
		Vao* vao
	) :
		m_shader_program(nullptr),
		m_texture(nullptr),
		m_vao(vao),
		m_model(1.0f)
	{
	}

	WorldMap::~WorldMap() {
	}

	bool WorldMap::onInit() {
		Game* game = getGame();
		ResourceManager* manager = game->getResourceManager();

		m_shader_program = manager->getShaderProgram("texture");
		m_texture = manager->getTexture("tilesheet");

		return true;
	}

	void WorldMap::onRender() {
		this->m_shader_program->bind();
		this->m_shader_program->setMatrix("model", this->m_model);
		this->m_shader_program->bindTexture("texture_id", this->m_texture->getID());
		this->m_vao->render();
	}

}