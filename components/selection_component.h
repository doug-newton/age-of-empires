#pragma once

#include "../core/component.h"
#include "../subjects/selection_subject.h"

namespace aoe_engine {

	class SelectionComponent : public Component, public SelectionSubject {

	public:
		SelectionComponent();
		~SelectionComponent();

		void onEntityRegistration() override;
		bool onInit() override;
		void onClickUpdate(const ClickSubject* subject) override;

	};

}
