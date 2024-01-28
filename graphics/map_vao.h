#pragma once

#include "vao.h"

namespace aoe_engine {

	class MapVao : public Vao {

	public:
		MapVao();
		virtual ~MapVao();
		virtual bool onInit() override;

	private:
		GLfloat* createTiles(int** tiles, int w, int h, int* vertices_size);
		void createTile(GLfloat* vertices, int w, int h, int r, int c, int t);
		GLuint* createElements(int num_sides, int* num_elements, int* elements_size);

	};

}
