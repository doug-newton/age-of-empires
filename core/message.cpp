#include "message.h"
#include "component.h"

namespace aoe_engine {

	Message::Message(void* sender) :
		m_sender(sender) {
	}

	Message::~Message() {
	}

	void* Message::getSender() {
		return this->m_sender;
	}
}