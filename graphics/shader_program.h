#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class ShaderProgram {

public:

	ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
	~ShaderProgram();

	bool onInit();
	GLuint getID();

private:

	GLuint m_id;
	std::string m_vertex_path;
	std::string m_fragment_path;

	GLuint compileShader(const char* source, GLuint type);

};
