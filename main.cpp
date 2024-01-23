#include "core/driver.h"
#include "graphics/shader_program.h"
#include "core/resource_manager.h"

using namespace std;

bool load_resources(ResourceManager* manager) {
	ShaderProgram* shader = new ShaderProgram("res/vertex_shader.glsl", "res/fragment_shader.glsl");

	if (!shader->onInit()) {
		delete shader;
		return false;
	}

	try {
		manager->registerShaderProgram("basic", shader);
	}
	catch (resource_exists_exception ex) {
		delete shader;
		return false;
	}

	return true;
}

int main(int argc, char** argv)
{
	Driver::setResourceLoaderCallback(load_resources);
	bool init_success = Driver::onInit();

	if (init_success) {
		Driver::run();
	}

	Driver::onCleanUp();

	return 0;
}
