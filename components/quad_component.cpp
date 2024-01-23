#include "quad_component.h"
#include "../graphics/shader_program.h"
#include "../graphics/vao.h"
#include "transform_component.h"

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
	glm::vec2 pos = this->m_transform_component->getPosition();
	glm::vec2 dim = this->m_transform_component->getDimensions();
	float rotation = this->m_transform_component->getRotation();

	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(pos, 0.0f));
	model = glm::scale(model, glm::vec3(dim, 0.0f));
	model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 view(1.0f);

	GLuint program_id = this->m_shader_program->getID();
	GLuint vao_id = this->m_vao->getID();

	glUseProgram(program_id);
	this->m_shader_program->setMatrix("model", model);
	this->m_shader_program->setMatrix("view", view);

	glBindVertexArray(vao_id);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
}

