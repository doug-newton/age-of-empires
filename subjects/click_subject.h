#pragma once

#include "../core/subject.h"

namespace aoe_engine {

	class ClickSubject : public Subject {

	public:

		ClickSubject();
		virtual ~ClickSubject();

		void notify(Subscriber* subscriber) override;

		bool aabb_clicked;
		int button;
		int action;
		int mods;
		double world_x;
		double world_y;

	};

}
