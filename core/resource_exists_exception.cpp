#include "resource_exists_exception.h"

namespace aoe_engine {

	const char* resource_exists_exception::what() const {
		return "resource already exists";
	}

}
