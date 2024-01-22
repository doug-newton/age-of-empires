#include "shader.h"
#include "../util/file_util.h"
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) :
	m_id(0),
	m_vertex_path(vertexPath),
	m_fragment_path(fragmentPath) {
}

Shader::~Shader() {
	glDeleteProgram(m_id);
}

bool Shader::onInit() {
	std::string vertex_source = read_file(m_vertex_path);
	GLuint vertex_shader_id = compileShader(vertex_source.c_str(), GL_VERTEX_SHADER);

	if (vertex_shader_id == 0) {
		return false;
	}

	std::string fragment_source = read_file(m_fragment_path);
	GLuint fragment_shader_id = compileShader(fragment_source.c_str(), GL_FRAGMENT_SHADER);

	if (fragment_shader_id == 0) {
		glDeleteShader(vertex_shader_id);
		return false;
	}

	m_id = glCreateProgram();
	glAttachShader(m_id, fragment_shader_id);
	glAttachShader(m_id, vertex_shader_id);
	glLinkProgram(m_id);

	int success;
	glGetProgramiv(m_id, GL_LINK_STATUS, &success);

	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(m_id, 512, NULL, infoLog);
		std::cerr << infoLog << std::endl;
	}

	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);

	return success != 0;
}

GLuint Shader::compileShader(const char* source, GLuint type) {
	GLuint shader_id = glCreateShader(type);
	glShaderSource(shader_id, 1, &source, NULL);
	glCompileShader(shader_id);

	int success = 0;

	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
		std::cerr << infoLog << std::endl;
		return 0;
	}

	return shader_id;
}
