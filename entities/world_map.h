#pragma once

#include "../core/game_object.h"

#include "../core/component.h"
#include "../graphics/shader_program.h"
#include "../graphics/texture.h"
#include "../graphics/vao.h"
#include <string>
#include <glm/glm.hpp>

#include "../graphics/map_vao.h"

namespace aoe_engine {

	class WorldMap : public GameObject {

	public:

		WorldMap();

		~WorldMap();

		virtual bool onInit() override;
		virtual void onRender() override;

	private:

		MapVao m_map_vao;

		ShaderProgram* m_shader_program;
		Texture* m_texture;

		glm::mat4 m_model;

	};

}
