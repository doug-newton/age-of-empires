#include "resource_manager.h"

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
	for (auto it = m_shader_programs.begin(); it != m_shader_programs.end(); ++it) {
		delete (*it).second;
	}
}

void ResourceManager::registerShaderProgram(const std::string& name, ShaderProgram* shaderProgram) {
	if (m_shader_programs.find(name) != m_shader_programs.end()) {
		throw new resource_exists_exception();
	}

	m_shader_programs[name] = shaderProgram;
}

ShaderProgram* ResourceManager::getShaderProgram(const std::string& name) {
	auto result = m_shader_programs.find(name);

	if (result == m_shader_programs.end()) {
		return nullptr;
	}

	return (*result).second;
}
