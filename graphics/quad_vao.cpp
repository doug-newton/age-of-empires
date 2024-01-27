#include "quad_vao.h"

namespace aoe_engine {

	QuadVao::QuadVao() {
	}

	QuadVao::~QuadVao() {
	}

	bool QuadVao::onInit() {
		glGenVertexArrays(1, &this->m_id);
		glBindVertexArray(this->m_id);

		GLfloat vertices[] = {
			-0.5f, -0.5f, 1.0f,		0.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, 1.0f,		0.0f, 0.0f, 1.0f, 1.0f,
			 0.5f,  0.5f, 1.0f,		0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 1.0f,		0.0f, 0.0f, 1.0f, 1.0f,
		};

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		GLuint elements[] = {
			0, 1, 2,
			2, 3, 0
		};

		this->n_num_elements = 6;

		GLuint ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

		glBindVertexArray(0);

		return true;
	}

}
