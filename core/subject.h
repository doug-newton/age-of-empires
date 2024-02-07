#pragma once
#include <vector>
#include <string>
#include "subscriber.h"
#include "subject_registry.h"

namespace aoe_engine {

	class Subject {

	public:
		Subject(const std::string& name);
		virtual ~Subject();

		void addSubscriber(Subscriber* subscriber);

	protected:

		void publish();
		virtual void notify(Subscriber* subscriber) = 0;
		void registerSubject(SubjectRegistry* registry);

	private:

		std::string m_name;
		std::vector<Subscriber*> m_subscribers;

	};

}
