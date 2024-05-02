#include "world_map.h"

namespace aoe_engine {

	WorldMap::WorldMap(
		ShaderProgram* shader_program,
		Texture* texture,
		Vao* vao
	) :
		m_shader_program(shader_program),
		m_texture(texture),
		m_vao(vao),
		m_model(1.0f)
	{
	}

	WorldMap::~WorldMap() {
	}

	void WorldMap::onRender() {
		this->m_shader_program->bind();
		this->m_shader_program->setMatrix("model", this->m_model);
		this->m_shader_program->bindTexture("texture_id", this->m_texture->getID());
		this->m_vao->render();
	}

}