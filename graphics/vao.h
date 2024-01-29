#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "resource.h"

namespace aoe_engine {

	class Vao: public Resource {
	public:

		Vao();
		virtual ~Vao();

		GLuint getID();

		void bind();

		void render();

	protected:
		GLuint m_id;
		int m_num_elements;

	};

}
