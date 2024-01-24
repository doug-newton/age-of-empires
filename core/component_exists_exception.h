#pragma once

#include <exception>

namespace aoe_engine {

	class component_exists_exception : public std::exception {
	public:
		const char* what() const override;
	};

}
