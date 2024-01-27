#include "camera_component.h"
#include "transform_component.h"
#include "../graphics/shader_program.h"

namespace aoe_engine {

	CameraComponent::CameraComponent(std::vector<std::string> programNames) :
		Component("camera"),
		m_transform_component(nullptr),
		m_program_names(programNames),
		m_shader_programs(0) {
	}

	CameraComponent::~CameraComponent() {
	}

	bool CameraComponent::onInit() {
		void* p_transform_component = findComponent("transform");
		this->m_transform_component = static_cast<TransformComponent*>(p_transform_component);

		if (this->m_transform_component == nullptr) {
			return false;
		}

		ResourceManager* mgr = getResourceManager();

		for (auto it = this->m_program_names.begin(); it != m_program_names.end(); ++it) {
			ShaderProgram* shader_program = mgr->getShaderProgram(*it);
			if (shader_program == nullptr) {
				return false;
			}
			this->m_shader_programs.push_back(shader_program);
		}

		return true;
	}

	void CameraComponent::onRender() {
		glm::vec2 translation = this->m_transform_component->getTranslation();

		glm::mat4 view(1.0);
		view = glm::translate(view, glm::vec3(-translation.x, -translation.y, 0.0f));

		for (auto it = this->m_shader_programs.begin(); it != this->m_shader_programs.end(); it++) {
			(*it)->bind();
			(*it)->setMatrix("view", view);
		}
	}

}