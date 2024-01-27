#include "quad_component.h"
#include "../graphics/shader_program.h"
#include "../graphics/vao.h"
#include "transform_component.h"

namespace aoe_engine {

	QuadComponent::QuadComponent() : Component("quad"),
		m_shader_program(0),
		m_vao(0),
		m_transform_component(nullptr) {
	}

	QuadComponent::~QuadComponent() {}

	bool QuadComponent::onInit() {
		ResourceManager* mgr = getResourceManager();

		this->m_shader_program = mgr->getShaderProgram("transform");
		this->m_vao = mgr->getVao("quad");
		void* p_transform_component = findComponent("transform");
		this->m_transform_component = static_cast<TransformComponent*>(p_transform_component);

		if (this->m_shader_program == nullptr ||
			this->m_vao == nullptr ||
			this->m_transform_component == nullptr) {
			return false;
		}

		return true;
	}

	void QuadComponent::onRender() {
		glm::mat4 model = this->m_transform_component->createModelMatrix();

		this->m_shader_program->bind();
		this->m_shader_program->setMatrix("model", model);

		this->m_vao->render();
	}

}
