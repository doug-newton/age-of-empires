#include "animated_sprite_component.h"
#include "../graphics/texture.h"
#include "../graphics/shader_program.h"
#include "transform_component.h"
#include "../subjects/movement_subject.h"

namespace aoe_engine {

	AnimatedSpriteComponent::AnimatedSpriteComponent(const std::string& texture_name, const std::string& vao_name) :
		Component("animated_sprite"),
		m_texture_name(texture_name),
		m_vao_name(vao_name),
		m_shader_program(nullptr),
		m_texture(nullptr),
		m_vao(nullptr),
		m_model(1.0f),
		m_sprite_x(1.0f),
		m_sprite_y(0.0f) {
	}

	bool AnimatedSpriteComponent::onInit() {
		subscribe("transform");
		subscribe("movement");

		this->m_shader_program = getShaderProgram("animated_texture");
		this->m_texture = getTexture(this->m_texture_name);
		this->m_vao = getVao(this->m_vao_name);

		if (this->m_shader_program == nullptr ||
			this->m_texture == nullptr ||
			this->m_vao == nullptr) {
			return false;
		}

		return true;
	}

	void AnimatedSpriteComponent::onRender() {
		this->m_shader_program->bind();
		this->m_shader_program->setVec2("sprite_pos", glm::vec2(this->m_sprite_x, this->m_sprite_y));
		this->m_shader_program->setVec2("spritesheet_dim", glm::vec2(4.0f, 1.0f));
		this->m_shader_program->setMatrix("model", this->m_model);
		this->m_shader_program->bindTexture("texture_id", this->m_texture->getID());
		this->m_vao->render();
	}

	void AnimatedSpriteComponent::onTransformUpdate(const TransformSubject* subject) {
		this->m_model = glm::mat4(1.0f);
		this->m_model = glm::translate(this->m_model, glm::vec3(subject->translation, 0.0f));
		this->m_model = glm::scale(this->m_model, glm::vec3(subject->scaling, 0.0f));
		this->m_model = glm::rotate(this->m_model, glm::radians(subject->rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	}

	void AnimatedSpriteComponent::onMovementUpdate(const MovementSubject* subject) {
		if (subject->moving_left) {
			this->m_sprite_x = 2.0f;
			return;
		}
		if (subject->moving_right) {
			this->m_sprite_x = 0.0f;
			return;
		}
		this->m_sprite_x = 1.0f;
	}

}