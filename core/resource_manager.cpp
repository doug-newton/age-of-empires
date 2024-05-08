#include "resource_manager.h"
#include <type_traits>

namespace aoe_engine {

	ResourceManager::ResourceManager() {
	}

	ResourceManager::~ResourceManager() {
		for (auto it = m_shader_programs.begin(); it != m_shader_programs.end(); ++it) {
			delete (*it).second;
		}
		for (auto it = m_custom_vaos.begin(); it != m_custom_vaos.end(); ++it) {
			delete (*it).second;
		}
		for (auto it = m_textures.begin(); it != m_textures.end(); ++it) {
			delete (*it).second;
		}
	}

	bool ResourceManager::onInit() {
		return true;
	}

	ShaderProgram* ResourceManager::getShaderProgram(const std::string& name) {
		auto result = m_shader_programs.find(name);

		if (result != m_shader_programs.end()) {
			return (*result).second;
		}

		ShaderProgram* shader_program = new ShaderProgram(name);

		if (!shader_program->onInit()) {
			delete shader_program;
			return nullptr;
		}

		m_shader_programs[name] = shader_program;
		return shader_program;
	}

	CustomVao* ResourceManager::getCustomVao(const std::string& name) {
		auto result = m_custom_vaos.find(name);

		if (result != m_custom_vaos.end()) {
			return (*result).second;
		}

		CustomVao* vao = new CustomVao(name);

		if (!vao->onInit()) {
			delete vao;
			return nullptr;
		}

		m_custom_vaos[name] = vao;
		return vao;
	}

	Texture* ResourceManager::getTexture(const std::string& name) {
		auto result = m_textures.find(name);

		if (result != m_textures.end()) {
			return (*result).second;
		}

		Texture* texture = new Texture(name);

		if (!texture->onInit()) {
			delete texture;
			return nullptr;
		}

		m_textures[name] = texture;
		return texture;
	}

}
