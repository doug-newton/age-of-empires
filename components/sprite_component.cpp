#include "sprite_component.h"
#include "transform_component.h"
#include "../core/resource_manager.h"

namespace aoe_engine {

	SpriteComponent::SpriteComponent(const std::string& texture_name) :
		Component("sprite"),
		m_shader_program(nullptr),
		m_texture(nullptr),
		m_transform_component(nullptr),
		m_texture_name(texture_name) {
	}

	SpriteComponent::~SpriteComponent() {
	}

	bool SpriteComponent::onInit() {

		ResourceManager* mgr = getResourceManager();
		this->m_shader_program = mgr->getShaderProgram("texture");
		this->m_texture = mgr->getTexture(this->m_texture_name);

		void* p_transform_component = findComponent("transform");
		this->m_transform_component = static_cast<TransformComponent*>(p_transform_component);

		if (
			this->m_shader_program == nullptr ||
			this->m_texture == nullptr ||
			this->m_transform_component == nullptr) {
			return false;
		}

		return true;
	}

	void SpriteComponent::onRender() {
		glm::mat4 model = this->m_transform_component->createModelMatrix();

		// TODO bind shader, model matrix, texture, vao, and draw geometry
	}

}