#pragma once
#include <string>

namespace aoe_engine {

	class Subject;

	class SubjectRegistry {

	public:
		virtual void registerSubject(const std::string& name, Subject* subject) = 0;
		virtual Subject* getSubject(const std::string&) = 0;

	};

}
