#include "subject.h"
#include "subject_registry.h"

namespace aoe_engine {

	Subject::Subject(const std::string& name) :
		m_name(name),
		m_subscribers(0)
	{
	}

	Subject::~Subject() {
	}

	void Subject::addSubscriber(Subscriber* subscriber) {
		this->m_subscribers.push_back(subscriber);
		notify(subscriber);
	}

	void Subject::publish() {
		for (auto it = m_subscribers.begin(); it != m_subscribers.end(); ++it) {
			notify(*it);
		}
	}

	void Subject::registerSubject(SubjectRegistry* registry) {
		registry->registerSubject(this->m_name, this);
	}

}