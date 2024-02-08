#include "view_component.h"
#include "transform_component.h"
#include "../graphics/shader_program.h"

namespace aoe_engine {

	ViewComponent::ViewComponent(std::vector<std::string> programNames) :
		Component("view"),
		m_program_names(programNames),
		m_shader_programs(0),
		m_aspect_ratio(1.0f),
		m_view(1.0f) {
	}

	ViewComponent::~ViewComponent() {
	}

	bool ViewComponent::onInit() {
		subscribe("transform");

		for (auto it = this->m_program_names.begin(); it != m_program_names.end(); ++it) {
			ShaderProgram* shader_program = getShaderProgram(*it);
			if (shader_program == nullptr) {
				return false;
			}
			this->m_shader_programs.push_back(shader_program);
		}

		return true;
	}

	void ViewComponent::onRender() {
		for (auto it = this->m_shader_programs.begin(); it != this->m_shader_programs.end(); it++) {
			(*it)->bind();
			(*it)->setMatrix("view", this->m_view);
		}
	}

	void ViewComponent::onWindowResize(int width, int height) {
		m_aspect_ratio = ((float)width) / height;
	}

	void ViewComponent::onTransformUpdate(const TransformSubject* subject) {
		this->m_view = glm::mat4(1.0);
		this->m_view = glm::translate(this->m_view, glm::vec3(-subject->translation.x, -subject->translation.y, 0.0f));
		this->m_view = glm::scale(this->m_view, glm::vec3((1/subject->scaling.x), (1 / subject->scaling.y)*m_aspect_ratio, 0.0f));
	}

	float ViewComponent::getAspectRatio() {
		return this->m_aspect_ratio;
	}

}