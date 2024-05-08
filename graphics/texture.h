#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace aoe_engine {

	class Texture {

	public:

		Texture(const std::string& name);
		~Texture();

		GLuint getID();
		bool onInit();

	private:

		GLuint m_id;
		std::string m_name;

	};

}
