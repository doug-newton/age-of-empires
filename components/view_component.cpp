#include "view_component.h"
#include "transform_component.h"
#include "../graphics/shader_program.h"
#include "../core/entity.h"

namespace aoe_engine {

	ViewComponent::ViewComponent(std::vector<std::string> programNames) :
		Component("view"),
		ViewSubject(),
		m_program_names(programNames),
		m_shader_programs(0),
		m_view(1.0f) {
	}

	ViewComponent::~ViewComponent() {
	}

	void ViewComponent::onEntityRegistration() {
		camera = this->getParent();
		registerSubject(camera);
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
		aspect_ratio = ((float)width) / height;
		updateView();
		publish();
	}

	void ViewComponent::onTransformUpdate(const TransformSubject* subject) {
		this->translation.x = subject->translation.x;
		this->translation.y = subject->translation.y;
		this->scaling.x = subject->scaling.x;
		this->scaling.y = subject->scaling.y;
		updateView();
		publish();
	}

	float ViewComponent::getAspectRatio() {
		return this->aspect_ratio;
	}

	void ViewComponent::updateView() {
		this->m_view = glm::mat4(1.0);
		this->m_view = glm::scale(this->m_view, glm::vec3((1/this->scaling.x), (1 / this->scaling.y)*aspect_ratio, 0.0f));
		this->m_view = glm::translate(this->m_view, glm::vec3(-this->translation.x, -this->translation.y, 0.0f));
	}

}