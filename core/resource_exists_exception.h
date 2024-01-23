#pragma once

#include <stdexcept>

class resource_exists_exception : public std::exception {
public:
	const char* what() const override;
};
