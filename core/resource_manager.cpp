#include "resource_manager.h"

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
}

void ResourceManager::registerShaderProgram(const std::string& name, ShaderProgram* shaderProgram) {
	this->m_shader_program_manager.registerShaderProgram(name, shaderProgram);
}

ShaderProgram* ResourceManager::getShaderProgram(const std::string& name) {
	return this->m_shader_program_manager.getShaderProgram(name);
}
