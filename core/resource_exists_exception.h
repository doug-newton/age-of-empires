#pragma once

#include <stdexcept>

namespace aoe_engine {

	class resource_exists_exception : public std::exception {
	public:
		const char* what() const override;
	};

}

