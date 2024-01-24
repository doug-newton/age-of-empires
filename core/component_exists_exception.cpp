#include "component_exists_exception.h"

namespace aoe_engine {

	const char* component_exists_exception::what() const {
		return "component already added";
	}

}