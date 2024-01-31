#pragma once

#include "../core/component.h"

namespace aoe_engine {

	class Texture;
	class ShaderProgram;
	class TransformComponent;
	class Vao;

	class AnimatedSpriteComponent: public Component {

	public:

		AnimatedSpriteComponent(const std::string& texture_name, const std::string& vao_name);

		bool onInit() override;
		void onRender() override;

	private:

		std::string m_texture_name;
		std::string m_vao_name;

		TransformComponent* m_transform_component;
		ShaderProgram* m_shader_program;
		Texture* m_texture;
		Vao* m_vao;

	};

}
