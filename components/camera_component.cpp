#include "camera_component.h"
#include "transform_component.h"
#include "../graphics/shader_program.h"

namespace aoe_engine {

	CameraComponent::CameraComponent(std::vector<std::string> programNames) :
		Component("camera"),
		m_transform_component(nullptr),
		m_program_names(programNames),
		m_shader_programs(0),
		m_aspect_ratio(1.0f) {
	}

	CameraComponent::~CameraComponent() {
	}

	bool CameraComponent::onInit() {
		this->m_transform_component = getComponent<TransformComponent>("transform");

		if (this->m_transform_component == nullptr) {
			return false;
		}

		for (auto it = this->m_program_names.begin(); it != m_program_names.end(); ++it) {
			ShaderProgram* shader_program = getShaderProgram(*it);
			if (shader_program == nullptr) {
				return false;
			}
			this->m_shader_programs.push_back(shader_program);
		}

		return true;
	}

	void CameraComponent::onRender() {
		glm::vec2 translation = this->m_transform_component->getTranslation();
		glm::vec2 scaling = this->m_transform_component->getScaling();

		glm::mat4 view(1.0);
		view = glm::translate(view, glm::vec3(-translation.x, -translation.y, 0.0f));
		view = glm::scale(view, glm::vec3((1/scaling.x), (1 / scaling.y)*m_aspect_ratio, 0.0f));

		for (auto it = this->m_shader_programs.begin(); it != this->m_shader_programs.end(); it++) {
			(*it)->bind();
			(*it)->setMatrix("view", view);
		}
	}

	void CameraComponent::onWindowResize(int width, int height) {
		m_aspect_ratio = ((float)width) / height;
	}

	float CameraComponent::getAspectRatio() {
		return this->m_aspect_ratio;
	}

}