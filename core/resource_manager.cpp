#include "resource_manager.h"

namespace aoe_engine {

	ResourceManager::ResourceManager() {
	}

	ResourceManager::~ResourceManager() {
	}

	void ResourceManager::registerShaderProgram(const std::string& name, ShaderProgram* shaderProgram) {
		this->m_shader_program_manager.registerResource(name, shaderProgram);
	}

	ShaderProgram* ResourceManager::getShaderProgram(const std::string& name) {
		return this->m_shader_program_manager.getResource(name);
	}

	void ResourceManager::registerVao(const std::string& name, Vao* vao) {
		this->m_vao_manager.registerResource(name, vao);
	}

	Vao* ResourceManager::getVao(const std::string& name) {
		return this->m_vao_manager.getResource(name);
	}

	void ResourceManager::registerTexture(const std::string& name, Texture* texture) {
		this->m_texture_manager.registerResource(name, texture);
	}

	Texture* ResourceManager::getTexture(const std::string& name) {
		return this->m_texture_manager.getResource(name);
	}

}
