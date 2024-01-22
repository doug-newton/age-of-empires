#pragma once

#include <exception>

class component_exists_exception : public std::exception {
public:
	const char* what() const override;
};
