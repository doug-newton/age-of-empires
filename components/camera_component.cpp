#include "camera_component.h"
#include "transform_component.h"
#include "../graphics/shader_program.h"

CameraComponent::CameraComponent() :
	Component("camera"),
	m_transform_component(nullptr),
	m_transform_shader_program(nullptr) {
}

CameraComponent::~CameraComponent() {
}

bool CameraComponent::onInit() {
	void* p_transform_component = findComponent("transform");
	this->m_transform_component = static_cast<TransformComponent*>(p_transform_component);

	ResourceManager* mgr = getResourceManager();
	this->m_transform_shader_program = mgr->getShaderProgram("transform");

	if (this->m_transform_component == nullptr || this->m_transform_shader_program == nullptr) {
		return false;
	}

	return true;
}

void CameraComponent::onRender() {
	glm::vec2 translation = this->m_transform_component->getTranslation();

	glm::mat4 view(1.0);
	view = glm::translate(view, glm::vec3(-translation.x, -translation.y, 0.0f));

	this->m_transform_shader_program->setMatrix("view", view);
}