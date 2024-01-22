#include "component_exists_exception.h"

const char* component_exists_exception::what() const {
	return "component already added";
}