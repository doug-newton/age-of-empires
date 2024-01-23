#include "core/driver.h"
#include "graphics/shader.h"

using namespace std;

int main(int argc, char** argv)
{
	bool init_success = Driver::onInit();

	{
		Shader shader("res/vertex_shader.glsl", "res/fragment_shader.glsl");
		init_success = init_success && shader.onInit();

		if (init_success) {
			Driver::run();
		}
	}

	Driver::onCleanUp();

	return 0;
}
