#pragma once

#include "../core/component.h"
#include "../graphics/shader_program.h"
#include "../graphics/texture.h"
#include "../graphics/vao.h"
#include <string>
#include <glm/glm.hpp>

namespace aoe_engine {

	class SpriteComponent : public Component {

	public:
		SpriteComponent(const std::string& texture_name, const std::string& vao_name);
		virtual ~SpriteComponent();

		virtual bool onInit() override;
		virtual void onRender() override;
		void onTransformUpdate(const TransformSubject* subject);

	private:
		ShaderProgram* m_shader_program;
		Texture* m_texture;
		Vao* m_vao;
		std::string m_texture_name;
		std::string m_vao_name;

		glm::mat4 m_model;

	};

}
