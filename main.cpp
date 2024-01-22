#include "core/driver.h"

using namespace std;

int main (int argc, char ** argv)
{
	bool init_success = Driver::onInit();

	if (init_success) {
		Driver::run();
	}

	Driver::onCleanUp();

	return 0;
}
