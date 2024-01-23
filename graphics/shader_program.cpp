#include "shader_program.h"
#include "../util/file_util.h"
#include <iostream>

ShaderProgram::ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) :
	m_id(0),
	m_vertex_path(vertexPath),
	m_fragment_path(fragmentPath) {
}

ShaderProgram::~ShaderProgram() {
	if (this->m_id == 0) {
		return;
	}
	glDeleteProgram(m_id);
}

bool ShaderProgram::onInit() {
	bool success = true;

	Shader vertex_shader(GL_VERTEX_SHADER, this->m_vertex_path);
	success = success && vertex_shader.loadAndCompile();

	Shader fragment_shader(GL_FRAGMENT_SHADER, this->m_fragment_path);
	success = success && vertex_shader.loadAndCompile();

	success = success && attachAndLinkShaders(vertex_shader, fragment_shader);

	if (!success) {
		return false;
	}

	return true;
}

GLuint ShaderProgram::getID() const {
	return this->m_id;
}

bool ShaderProgram::attachAndLinkShaders(const Shader& vertex_shader, const Shader& fragment_shader) {
	this->m_id = glCreateProgram();
	glAttachShader(this->m_id, vertex_shader.getID());
	glAttachShader(this->m_id, fragment_shader.getID());
	glLinkProgram(this->m_id);

	int link_status;
	glGetProgramiv(this->m_id, GL_LINK_STATUS, &link_status);

	if (!link_status) {
		char infoLog[512];
		glGetProgramInfoLog(this->m_id, 512, NULL, infoLog);
		std::cerr << infoLog << std::endl;
		this->m_id = 0;
		return false;
	}

	return true;
}
