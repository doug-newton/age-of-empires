#include "map_vao.h"

namespace aoe_engine {

	MapVao::MapVao() {
	}

	MapVao::~MapVao() {
	}

	bool MapVao::onInit() {
		glGenVertexArrays(1, &this->m_id);
		glBindVertexArray(this->m_id);

		GLfloat positions[] = {
			-0.5f, -0.5f, 1.0f,
			 0.5f, -0.5f, 1.0f,
			 0.5f,  0.5f, 1.0f,
			-0.5f,  0.5f, 1.0f
		};

		GLuint tile_coords[] = {
			0, 0,
			0, 0,
			0, 0,
			0, 0
		};

		GLuint positions_vbo;
		glGenBuffers(1, &positions_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, positions_vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		GLuint tile_coords_vbo;
		glGenBuffers(1, &tile_coords_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, tile_coords_vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(tile_coords), tile_coords, GL_STATIC_DRAW);

		glVertexAttribPointer(1, 2, GL_UNSIGNED_INT, GL_FALSE, 2 * sizeof(GLuint), (GLvoid*)(0));
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
