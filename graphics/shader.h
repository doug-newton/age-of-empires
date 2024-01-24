#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace aoe_engine {

	class Shader {
	public:
		Shader(GLuint type, const std::string& path);
		~Shader();

		GLuint getID() const;
		bool loadAndCompile();

	private:
		GLuint m_id;
		GLuint m_type;
		std::string m_path;
	};

}

