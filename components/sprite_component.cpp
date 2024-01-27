#include "sprite_component.h"
#include "transform_component.h"
#include "../core/resource_manager.h"

namespace aoe_engine {

	SpriteComponent::SpriteComponent(const std::string& texture_name) :
		Component("sprite"),
		m_shader_program(nullptr),
		m_texture(nullptr),
		m_vao(nullptr),
		m_transform_component(nullptr),
		m_texture_name(texture_name) {
	}

	SpriteComponent::~SpriteComponent() {
	}

	bool SpriteComponent::onInit() {

		ResourceManager* mgr = getResourceManager();
		this->m_shader_program = mgr->getShaderProgram("texture");
		this->m_texture = mgr->getTexture(this->m_texture_name);
		this->m_vao = mgr->getVao("sprite");

		void* p_transform_component = findComponent("transform");
		this->m_transform_component = static_cast<TransformComponent*>(p_transform_component);

		if (
			this->m_shader_program == nullptr ||
			this->m_texture == nullptr ||
			this->m_vao == nullptr ||
			this->m_transform_component == nullptr) {
			return false;
		}

		return true;
	}

	void SpriteComponent::onRender() {
		glm::mat4 model = this->m_transform_component->createModelMatrix();

		this->m_shader_program->bind();
		this->m_shader_program->setMatrix("model", model);
		this->m_shader_program->bindTexture("texture_id", this->m_texture->getID());

		this->m_vao->bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
	}

}