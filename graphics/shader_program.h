#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "resource.h"
#include "shader.h"

namespace aoe_engine {

	class ShaderProgram: public Resource {

	public:

		ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
		~ShaderProgram();

		virtual bool onInit() override;
		GLuint getID() const;

		void bind() const;

		void setMatrix(const std::string& uniformName, const glm::mat4& matrix);
		void setVec2(const std::string& uniformName, const glm::vec2& vec2);
		void bindTexture(const std::string& uniformName, const GLuint textureID);

	private:

		GLuint m_id;
		std::string m_vertex_path;
		std::string m_fragment_path;

		bool attachAndLinkShaders(const Shader& vertex_shader, const Shader& fragment_shader);

	};

}
