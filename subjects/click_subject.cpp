#include "click_subject.h"

namespace aoe_engine {

	ClickSubject::ClickSubject() :
		Subject("click"),
		aabb_clicked(false),
		button(0),
		action(0),
		mods(0),
		world_x(0.0f),
		world_y(0.0f) {
	}

	ClickSubject::~ClickSubject() {
	}

	void ClickSubject::notify(Subscriber* subscriber) {
		subscriber->onClickUpdate(this);
	}

}
