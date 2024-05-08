#pragma once

#include <map>
#include <string>
#include "../graphics/shader_program.h"
#include "../graphics/custom_vao.h"
#include "../graphics/texture.h"
#include "resource_exists_exception.h"
#include "resource_map.h"

namespace aoe_engine {

	class ResourceManager {
	public:
		ResourceManager();
		~ResourceManager();

		bool onInit();

		ShaderProgram* getShaderProgram(const std::string& name);
		CustomVao* getCustomVao(const std::string& name);
		Texture* getTexture(const std::string& name);

	private:
		std::map<std::string, ShaderProgram*> m_shader_programs;
		std::map<std::string, CustomVao*> m_custom_vaos;
		std::map<std::string, Texture*> m_textures;

	};

}
