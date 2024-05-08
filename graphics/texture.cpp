#include "texture.h"
#include "../stb_image.h"

namespace aoe_engine {

	Texture::Texture(const std::string& name) :
		m_id(0),
		m_name(name) {
	}

	Texture::~Texture() {
		if (this->m_id == 0) {
			return;
		}
		glDeleteTextures(1, &this->m_id);
	}

	GLuint Texture::getID() {
		return this->m_id;
	}

	bool Texture::onInit() {
		int width, height, numChannels;

		std::string path("res/images/" + this->m_name + ".png");

		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &numChannels, 0);

		glGenTextures(1, &this->m_id);
		glBindTexture(GL_TEXTURE_2D, this->m_id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(data);

		return true;
	}

}
