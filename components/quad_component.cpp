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

	this->m_shader_program = mgr->getShaderProgram("basic");
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
	GLuint program_id = this->m_shader_program->getID();
	GLuint vao_id = this->m_vao->getID();
	glUseProgram(program_id);
	glBindVertexArray(vao_id);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
}

