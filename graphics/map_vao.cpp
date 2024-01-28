#include "map_vao.h"
#include <iostream>

namespace aoe_engine {

	void create_tile(GLfloat* vertices, int w, int h, int r, int c, int t) {
		int quad = r * w + c;
		int begin = quad * 4 * 5;

		float map_left = -w * 1.0f / 2;
		float map_bottom = h * 1.0f / 2;

		int sides_x[] = { 0, 1, 1, 0 };
		int sides_y[] = { 0, 0, 1, 1 };

		int tile_dim = 2;
		int tc_x = t % tile_dim;
		int tc_y = t / tile_dim;
		float tile_sz = 1.0f / tile_dim;

		for (int i = 0; i < 4; i++) {
			int side_x = sides_x[i];
			int side_y = sides_y[i];

			std::cout << side_x << ", " << side_y << std::endl;

			vertices[begin + i * 5 + 0] = map_left + (side_x + c) * 0.5f - 0.5f;
			vertices[begin + i * 5 + 1] = map_bottom - ((side_y + r) * 0.5f - 0.5f);
			vertices[begin + i * 5 + 2] = 1.0f;
			vertices[begin + i * 5 + 3] = (tc_x + side_x) * tile_sz;
			vertices[begin + i * 5 + 4] = (tc_y + (1-side_y)) * tile_sz;
		}
	}

	GLfloat* create_tiles(int** tiles, int w, int h, int* vertices_size) {
		int num_attributes = h * w * 4 * 5;
		std::cout << num_attributes << std::endl;
		GLfloat* vertices = new GLfloat[num_attributes];

		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				int t = tiles[r][c];
				create_tile(vertices, w, h, r, c, t);
			}
		}

		*vertices_size = num_attributes * sizeof(GLfloat);

		return vertices;
	}

	GLuint* create_elements(int num_sides, int* num_elements, int * elements_size) {
		*num_elements = num_sides * 6;
		GLuint* elements = new GLuint[*num_elements];
		GLuint points[] = { 0, 1, 2, 2, 3, 0 };

		for (int s = 0; s < num_sides; s++) {
			for (int p = 0; p < 6; p++) {
				elements[s * 6 + p] = points[p] + s * 4;
			}
		}

		*elements_size = (*num_elements) * sizeof(int);

		return elements;
	}


	MapVao::MapVao() {
	}

	MapVao::~MapVao() {
	}

	bool MapVao::onInit() {
		glGenVertexArrays(1, &this->m_id);
		glBindVertexArray(this->m_id);

		int w = 4;
		int h = 4;

		int** tiles = new int* [h];
		for (int r = 0; r < h; r++) {
			tiles[r] = new int[w];
		}

		tiles[0][0] = 0;
		tiles[0][1] = 0;
		tiles[0][2] = 0;
		tiles[0][3] = 1;

		tiles[1][0] = 1;
		tiles[1][1] = 1;
		tiles[1][2] = 1;
		tiles[1][3] = 1;

		tiles[2][0] = 2;
		tiles[2][1] = 2;
		tiles[2][2] = 2;
		tiles[2][3] = 2;

		tiles[3][0] = 3;
		tiles[3][1] = 3;
		tiles[3][2] = 3;
		tiles[3][3] = 3;

		int n_vertices_size;
		GLfloat* n_vertices = create_tiles(tiles, w, h, &n_vertices_size);

		for (int s = 0; s < w * h; s++) {
			for (int v = 0; v < 4; v++) {
				for (int a = 0; a < 5; a++) {
					std::cout << n_vertices[s * 4 * 5 + v * 5 + a] << ", ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, n_vertices_size, n_vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		int elements_size;
		GLuint* n_elements = create_elements(w * h, &this->n_num_elements, &elements_size);

		GLuint ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements_size, n_elements, GL_STATIC_DRAW);

		glBindVertexArray(0);

		delete[] tiles;
		delete[] n_elements;
		delete[] n_vertices;

		return true;
	}

}
