#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

#include "shader.h"

class ShaderProgram {

public:

	ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
	~ShaderProgram();

	bool onInit();
	GLuint getID() const;

private:

	GLuint m_id;
	std::string m_vertex_path;
	std::string m_fragment_path;

	bool attachAndLinkShaders(const Shader& vertex_shader, const Shader& fragment_shader);

};
