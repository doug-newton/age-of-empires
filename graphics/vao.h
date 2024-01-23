#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Vao {
public:

	Vao();
	virtual ~Vao();

	virtual bool onInit() = 0;

	GLuint getID();

protected:
	GLuint m_id;

};
