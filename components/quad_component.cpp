#include "quad_component.h"
#include "../graphics/shader_program.h"
#include "../graphics/vao.h"

QuadComponent::QuadComponent() : Component("quad"),
	m_shader_program(0),
	m_vao(0) {
}

QuadComponent::~QuadComponent() {}

bool QuadComponent::onInit() {
	ResourceManager* mgr = getResourceManager();

	this->m_shader_program = mgr->getShaderProgram("basic");
	this->m_vao = mgr->getVao("quad");

	if (this->m_shader_program == nullptr || this->m_vao == nullptr) {
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

