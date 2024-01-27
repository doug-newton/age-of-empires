#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"

namespace aoe_engine {

	class ShaderProgram {

	public:

		ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
		~ShaderProgram();

		bool onInit();
		GLuint getID() const;

		void bind() const;

		void setMatrix(const std::string& uniformName, const glm::mat4& matrix);

	private:

		GLuint m_id;
		std::string m_vertex_path;
		std::string m_fragment_path;

		bool attachAndLinkShaders(const Shader& vertex_shader, const Shader& fragment_shader);

	};

}
