#pragma once

#include <map>
#include <string>
#include "../graphics/shader_program.h"
#include "resource_exists_exception.h"

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

	void registerShaderProgram(const std::string& name, ShaderProgram* shader);
	ShaderProgram* getShaderProgram(const std::string& name);

private:
	std::map<std::string, ShaderProgram*> m_shader_programs;
};
