#include "selection_subject.h"

namespace aoe_engine {

	SelectionSubject::SelectionSubject() :
		Subject("selection"),
		selected(false) {
	}

	SelectionSubject::~SelectionSubject() {
	}

	void SelectionSubject::notify(Subscriber* subscriber) {
		subscriber->onSelectionUpdate(this);
	}

}
