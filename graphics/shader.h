#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class Shader {

public:

	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	bool onInit();
	GLuint getID();

private:

	GLuint m_id;
	std::string m_vertex_path;
	std::string m_fragment_path;

	GLuint compileShader(const char* source, GLuint type);

};
