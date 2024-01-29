#include "resource_manager.h"
#include <type_traits>

namespace aoe_engine {

	ResourceManager::ResourceManager() {
	}

	ResourceManager::~ResourceManager() {
	}

	bool ResourceManager::onInit() {
		bool success = true;

		success = success && this->m_shader_program_manager.onInit();
		success = success && this->m_vao_manager.onInit();
		success = success && this->m_texture_manager.onInit();

		return success;
	}

	void ResourceManager::registerShaderProgram(const std::string& name, ShaderProgram* shaderProgram) {
		this->m_shader_program_manager.registerResource(name, shaderProgram);
	}

	ShaderProgram* ResourceManager::getShaderProgram(const std::string& name) {
		return getResource<ShaderProgram>(&this->m_shader_program_manager, name);
	}

	void ResourceManager::registerVao(const std::string& name, Vao* vao) {
		this->m_vao_manager.registerResource(name, vao);
	}

	Vao* ResourceManager::getVao(const std::string& name) {
		return getResource<Vao>(&this->m_vao_manager, name);
	}

	void ResourceManager::registerTexture(const std::string& name, Texture* texture) {
		this->m_texture_manager.registerResource(name, texture);
	}

	Texture* ResourceManager::getTexture(const std::string& name) {
		return getResource<Texture>(&this->m_texture_manager, name);
	}

	template <class ResourceType>
	ResourceType* ResourceManager::getResource(ResourceMap* map, const std::string& name) {
		static_assert(std::is_base_of<Resource, ResourceType>::value, "ResourceType must be derived from Resource");
		Resource* resource = map->getResource(name);
		if (resource == nullptr) {
			return nullptr;
		}
		return static_cast<ResourceType*>(resource);
	}

}
