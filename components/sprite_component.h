#pragma once

#include "../core/component.h"
#include "../graphics/shader_program.h"
#include "../graphics/texture.h"
#include "../graphics/vao.h"
#include <string>

namespace aoe_engine {

	class TransformComponent;

	class SpriteComponent : public Component {

	public:
		SpriteComponent(const std::string& texture_name);
		virtual ~SpriteComponent();

		virtual bool onInit() override;
		virtual void onRender() override;

	private:
		ShaderProgram* m_shader_program;
		Texture* m_texture;
		Vao* m_vao;
		TransformComponent* m_transform_component;
		std::string m_texture_name;

	};

}
