#include "resource_exists_exception.h"

const char* resource_exists_exception::what() const {
	return "resource already exists";
}