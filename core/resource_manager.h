#pragma once

#include <map>
#include <string>
#include "../graphics/shader_program.h"
#include "resource_exists_exception.h"
#include "generic_resource_manager.h"

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

	void registerShaderProgram(const std::string& name, ShaderProgram* shader);
	ShaderProgram* getShaderProgram(const std::string& name);

private:
	GenericResourceManager<ShaderProgram> m_shader_program_manager;

};
