#pragma once

#include "../core/subject.h"

namespace aoe_engine {

	class SelectionSubject : public Subject {

	public:

		SelectionSubject();
		virtual ~SelectionSubject();

		void notify(Subscriber* subscriber) override;

		bool selected;

	};

}
