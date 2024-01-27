#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace aoe_engine {

	class Vao {
	public:

		Vao();
		virtual ~Vao();

		virtual bool onInit() = 0;

		GLuint getID();

		void bind();

		void render();

	protected:
		GLuint m_id;
		int n_num_elements;

	};

}
