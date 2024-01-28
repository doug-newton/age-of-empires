#include "map_vao.h"
#include <iostream>

namespace aoe_engine {

	void create_tile(GLfloat* vertices, int w, int h, int r, int c, int t) {
		int quad = r * w + c;
		int begin = quad * 4 * 5;

		float map_left = -w * 1.0f / 2;
		float map_top = -h * 1.0f / 2;

		int sides_x[] = { 0, 1, 1, 0 };
		int sides_y[] = { 0, 0, 1, 1 };

		int tile_dim = 2;
		int tc_x = t % 2;
		int tc_y = t / 2;
		float tile_sz = 1.0f / tile_dim;

		for (int i = 0; i < 4; i++) {
			int side_x = sides_x[i];
			int side_y = sides_y[i];

			std::cout << side_x << ", " << side_y << std::endl;

			vertices[begin + i * 5 + 0] = map_left + (side_x + c) * 0.5f - 0.5f;
			vertices[begin + i * 5 + 1] = map_top + (side_y + r) * 0.5f - 0.5f;
			vertices[begin + i * 5 + 2] = 1.0f;
			vertices[begin + i * 5 + 3] = tc_x + side_x * tile_sz;
			vertices[begin + i * 5 + 4] = tc_y + side_y * tile_sz;
		}
	}

	GLuint* create_elements(int num_sides, int * elements_size) {
		int num_elements = num_sides * 6;
		GLuint* elements = new GLuint[num_elements];
		GLuint points[] = { 0, 1, 2, 2, 3, 0 };

		for (int s = 0; s < num_sides; s++) {
			for (int p = 0; p < 6; p++) {
				elements[s * 6 + p] = points[p] + s * 4;
			}
		}

		*elements_size = num_elements * sizeof(int);

		return elements;
	}


	MapVao::MapVao() {
	}

	MapVao::~MapVao() {
	}

	bool MapVao::onInit() {
		glGenVertexArrays(1, &this->m_id);
		glBindVertexArray(this->m_id);

		int w = 3;
		int h = 2;

		int tiles[2][3] = {
			{ 0, 3, 2},
			{ 2, 1, 2},
		};

		int num_floats = w * h * 4 * 5;
		GLfloat* n_vertices = new GLfloat[num_floats];

		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				int t = tiles[r][c];
				create_tile(n_vertices, w, h, r, c, t);
			}
		}

		for (int i = 0; i < num_floats; i++) {
			std::cout << n_vertices[i] << ", ";
			if ((i + 1) % 5 == 0) std::cout << std::endl;
		}

		for (int s = 0; s < w * h; s++) {
			for (int v = 0; v < 4; v++) {
				for (int a = 0; a < 5; a++) {
					std::cout << n_vertices[s * 4 * 5 + v * 5 + a] << ", ";
				}
			}
			std::cout << std::endl;
		}

		int n_elements_size;
		GLuint* n_elements = create_elements(w * h, &n_elements_size);

		GLfloat vertices[] = {
			-0.5f, -0.5f, 1.0f,		0.0f, 0.0f,
			 0.5f, -0.5f, 1.0f,		0.5f, 0.0f,
			 0.5f,  0.5f, 1.0f,		0.5f, 0.5f,
			-0.5f,  0.5f, 1.0f,		0.0f, 0.5f
		};

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		GLuint elements[] = {
			0, 1, 2,
			2, 3, 0
		};

		this->n_num_elements = 6;
		int e_sz = sizeof(elements);

		GLuint ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

		glBindVertexArray(0);

		delete[] n_elements;
		delete[] n_vertices;

		return true;
	}

}
