#include "quad_component.h"
#include "../graphics/shader_program.h"
#include "../graphics/vao.h"
#include "transform_component.h"

namespace aoe_engine {

	QuadComponent::QuadComponent() : Component("quad"),
		m_shader_program(0),
		m_vao(0),
		m_model(1.0f) {
	}

	QuadComponent::~QuadComponent() {}

	bool QuadComponent::onInit() {
		subscribe("transform");

		this->m_shader_program = getShaderProgram("transform");
		this->m_vao = getVao("quad");

		if (this->m_shader_program == nullptr ||
			this->m_vao == nullptr) {
			return false;
		}

		return true;
	}

	void QuadComponent::onRender() {

		this->m_shader_program->bind();
		this->m_shader_program->setMatrix("model", this->m_model);

		this->m_vao->render();
	}

	void QuadComponent::onTransformUpdate(const TransformSubject* subject) {
		this->m_model = glm::mat4(1.0f);
		this->m_model = glm::translate(this->m_model, glm::vec3(subject->translation, 0.0f));
		this->m_model = glm::scale(this->m_model, glm::vec3(subject->scaling, 0.0f));
		this->m_model = glm::rotate(this->m_model, glm::radians(subject->rotation), glm::vec3(0.0f, 0.0f, 1.0f));

	}

}
