#pragma once

namespace aoe_engine {

	class Component;

	class Message {

	public:
		Message(void* sender);
		void* getSender();
		virtual ~Message();

		virtual void accept(Component* component) = 0;

	private:
		void* m_sender;

	};

}
