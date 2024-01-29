#pragma once

#include <map>
#include <string>
#include "../graphics/shader_program.h"
#include "../graphics/vao.h"
#include "../graphics/texture.h"
#include "resource_exists_exception.h"
#include "resource_map.h"

namespace aoe_engine {

	class ResourceManager {
	public:
		ResourceManager();
		~ResourceManager();

		bool onInit();

		void registerShaderProgram(const std::string& name, ShaderProgram* shader);
		ShaderProgram* getShaderProgram(const std::string& name);

		void registerVao(const std::string& name, Vao* vao);
		Vao* getVao(const std::string& name);

		void registerTexture(const std::string& name, Texture* texture);
		Texture* getTexture(const std::string& name);

	private:

		template <class ResourceType>
		ResourceType* getResource(ResourceMap* map, const std::string& name);

		ResourceMap m_shader_program_manager;
		ResourceMap m_vao_manager;
		ResourceMap m_texture_manager;

	};

}
