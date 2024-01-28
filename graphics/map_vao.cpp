#include "map_vao.h"

namespace aoe_engine {

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

		int vertices_size;
		GLfloat* vertices = createTiles(tiles, w, h, &vertices_size);

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		int elements_size;
		GLuint* elements = createElements(w * h, &elements_size);

		GLuint ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements_size, elements, GL_STATIC_DRAW);

		glBindVertexArray(0);

		delete[] tiles;
		delete[] elements;
		delete[] vertices;

		return true;
	}

	void MapVao::createTile(GLfloat* vertices, int w, int h, int r, int c, int t) {
		int quad = r * w + c;
		int begin = quad * 4 * 5;

		float map_left = -(w * 1.0f) / 2;
		float map_bottom = (h * 1.0f) / 2;

		int sides_x[] = { 0, 1, 1, 0 };
		int sides_y[] = { 0, 0, 1, 1 };

		int tile_dim = 2;
		int tc_x = t % tile_dim;
		int tc_y = t / tile_dim;
		float tile_sz = 1.0f / tile_dim;

		for (int i = 0; i < 4; i++) {
			int side_x = sides_x[i];
			int side_y = sides_y[i];

			vertices[begin + i * 5 + 0] = map_left + (side_x + c);
			vertices[begin + i * 5 + 1] = map_bottom - (side_y + r);
			vertices[begin + i * 5 + 2] = 1.0f;
			vertices[begin + i * 5 + 3] = (tc_x + side_x) * tile_sz;
			vertices[begin + i * 5 + 4] = (tc_y + (1-side_y)) * tile_sz;
		}
	}

	GLfloat* MapVao::createTiles(int** tiles, int w, int h, int* vertices_size) {
		int num_attributes = h * w * 4 * 5;
		GLfloat* vertices = new GLfloat[num_attributes];

		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				int t = tiles[r][c];
				createTile(vertices, w, h, r, c, t);
			}
		}

		*vertices_size = num_attributes * sizeof(GLfloat);

		return vertices;
	}

	GLuint* MapVao::createElements(int num_sides, int * elements_size) {
		this->m_num_elements = num_sides * 6;
		GLuint* elements = new GLuint[this->m_num_elements];
		GLuint points[] = { 0, 1, 2, 2, 3, 0 };

		for (int s = 0; s < num_sides; s++) {
			for (int p = 0; p < 6; p++) {
				elements[s * 6 + p] = points[p] + s * 4;
			}
		}

		*elements_size = (this->m_num_elements) * sizeof(int);

		return elements;
	}

}
