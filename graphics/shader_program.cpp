#include "shader_program.h"
#include "../util/file_util.h"
#include <iostream>

namespace aoe_engine {

	ShaderProgram::ShaderProgram(const std::string& name) :
		m_id(0),
		m_name(name)
	{
	}

	ShaderProgram::~ShaderProgram() {
		if (this->m_id == 0) {
			return;
		}
		glDeleteProgram(m_id);
		this->m_id = 0;
	}

	bool ShaderProgram::onInit() {
		bool success = true;

		std::string m_vertex_path("res/shaders/" + m_name + ".vert");
		std::string m_fragment_path("res/shaders/" + m_name + ".frag");

		Shader vertex_shader(GL_VERTEX_SHADER, m_vertex_path);
		success = success && vertex_shader.loadAndCompile();

		Shader fragment_shader(GL_FRAGMENT_SHADER, m_fragment_path);
		success = success && fragment_shader.loadAndCompile();

		success = success && attachAndLinkShaders(vertex_shader, fragment_shader);

		if (!success) {
			return false;
		}

		return true;
	}

	GLuint ShaderProgram::getID() const {
		return this->m_id;
	}

	void ShaderProgram::bind() const {
		glUseProgram(this->m_id);
	}

	void ShaderProgram::setMatrix(const std::string& uniformName, const glm::mat4& matrix) {
		GLuint location = glGetUniformLocation(this->m_id, uniformName.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void ShaderProgram::setVec2(const std::string& uniformName, const glm::vec2& vec2) {
		GLuint location = glGetUniformLocation(this->m_id, uniformName.c_str());
		glUniform2fv(location, 1, glm::value_ptr(vec2));
	}

	void ShaderProgram::bindTexture(const std::string& uniformName, GLuint textureID) {
		GLuint location = glGetUniformLocation(this->m_id, uniformName.c_str());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glUniform1ui(location, 0);
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

}
