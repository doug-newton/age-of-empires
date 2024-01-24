#include "shader.h"
#include "../util/file_util.h"
#include <iostream>

namespace aoe_engine {

	Shader::Shader(GLuint type, const std::string& path) :
		m_id(0),
		m_type(type),
		m_path(path) {
	}

	Shader::~Shader() {
		if (this->m_id == 0) {
			return;
		}
		glDeleteShader(this->m_id);
		this->m_id = 0;
	}

	GLuint Shader::getID() const {
		return this->m_id;
	}

	bool Shader::loadAndCompile() {
		this->m_id = glCreateShader(this->m_type);

		if (this->m_id == 0) {
			return false;
		}

		std::string source = read_file(this->m_path);
		const char* source_c_str = source.c_str();

		glShaderSource(this->m_id, 1, &source_c_str, NULL);
		glCompileShader(this->m_id);

		int compile_status;
		glGetShaderiv(this->m_id, GL_COMPILE_STATUS, &compile_status);

		if (!compile_status) {
			char infoLog[512];
			glGetShaderInfoLog(this->m_id, 512, NULL, infoLog);
			std::cerr << "error compiling \"" << this->m_path << "\": " << infoLog << std::endl;
			this->m_id = 0;
			return false;
		}

		return true;
	}

}