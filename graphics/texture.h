#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

#include "resource.h"

namespace aoe_engine {

	class Texture: public Resource {

	public:

		Texture(const std::string& path);
		~Texture();

		GLuint getID();
		virtual bool onInit() override;

	private:

		GLuint m_id;
		std::string m_path;

	};

}
