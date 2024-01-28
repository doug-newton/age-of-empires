#pragma once

#include "vao.h"
#include <string>

namespace aoe_engine {

	class MapVao : public Vao {

	public:
		MapVao(const std::string& path);
		virtual ~MapVao();
		virtual bool onInit() override;

	private:
		std::string m_path;
		GLfloat* createTiles(int** tiles, int w, int h, int* vertices_size);
		void createTile(GLfloat* vertices, int w, int h, int r, int c, int t);
		GLuint* createElements(int num_sides, int* elements_size);
		int** readMap(const std::string& path, int* w, int* h);

	};

}
