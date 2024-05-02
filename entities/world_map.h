#pragma once

#include "../core/game_object.h"

#include "../core/component.h"
#include "../graphics/shader_program.h"
#include "../graphics/texture.h"
#include "../graphics/vao.h"
#include <string>
#include <glm/glm.hpp>

namespace aoe_engine {

	class WorldMap : public GameObject {

	public:

		WorldMap(
			ShaderProgram* shader_program,
			Texture* texture,
			Vao* vao
		);

		~WorldMap();

		virtual void onRender() override;

	private:

		ShaderProgram* m_shader_program;
		Texture* m_texture;
		Vao* m_vao;

		glm::mat4 m_model;

	};

}
