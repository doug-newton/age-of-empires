#include "init.h"
#include "core/driver.h"

using namespace aoe_engine;
using namespace aoe;

int main(int argc, char** argv)
{
	Driver::setWindowDetails("Age of Empires", 1280, 960);
	Driver::setResourceLoaderCallback(load_resources);
	Driver::setEntityLoaderCallback(load_entities);

	bool init_success = Driver::onInit();

	if (init_success) {
		Driver::run();
	}

	Driver::onCleanUp();

	return 0;
}
