#pragma once

#include "../core/component.h"
#include "../subjects/movement_subject.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class ClickMoverComponent : public Component, public MovementSubject {

	public:

		ClickMoverComponent();
		virtual ~ClickMoverComponent();

		void onEntityRegistration() override;
		bool onInit() override;

		void onTransformUpdate(const TransformSubject* subject);
		void onClickUpdate(const ClickSubject* subject);
		void onSelectionUpdate(const SelectionSubject* subject);

	private:
		bool m_selected;
		glm::vec2 m_position;

	};

}
