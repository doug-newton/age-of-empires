#pragma once

#include "../core/component.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class Texture;
	class ShaderProgram;
	class Vao;

	class AnimatedSpriteComponent: public Component {

	public:

		AnimatedSpriteComponent(const std::string& texture_name, const std::string& vao_name);

		bool onInit() override;
		void onRender() override;
		void onTransformUpdate(const TransformSubject* subject) override;
		void onMovementUpdate(const MovementSubject* subject) override;

	private:

		std::string m_texture_name;
		std::string m_vao_name;

		ShaderProgram* m_shader_program;
		Texture* m_texture;
		Vao* m_vao;
		glm::mat4 m_model;

		float m_sprite_x;
		float m_sprite_y;

	};

}

