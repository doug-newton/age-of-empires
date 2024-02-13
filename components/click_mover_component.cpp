#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "click_mover_component.h"
#include "../subjects/transform_subject.h"
#include "../subjects/click_subject.h"
#include "../subjects/selection_subject.h"
#include "../core/entity.h"

namespace aoe_engine {

	ClickMoverComponent::ClickMoverComponent() :
		Component("click_mover"),
		m_selected(false),
		m_position(0.0f, 0.0f) {
	}

	ClickMoverComponent::~ClickMoverComponent() {
	}

	void ClickMoverComponent::onEntityRegistration() {
		this->registerSubject(this->getParent());
	}
	
	bool ClickMoverComponent::onInit() {
		subscribe("transform");
		subscribe("selection");
		subscribe("click");
		return true;
	}

	void ClickMoverComponent::onTransformUpdate(const TransformSubject* subject) {
		this->m_position.x = subject->translation.x;
		this->m_position.y = subject->translation.y;
	}

	void ClickMoverComponent::onClickUpdate(const ClickSubject* subject) {
		if (this->m_selected == false) return;
		if (subject->aabb_clicked) return;
		if (subject->button != GLFW_MOUSE_BUTTON_RIGHT) return;
		if (subject->action != GLFW_RELEASE) return;

		moving_right = subject->world_x > this->m_position.x;
		moving_left = subject->world_x < this->m_position.x;
		moving_up = subject->world_y > this->m_position.y;
		moving_down = subject->world_y < this->m_position.y;

		publish();
	}

	void ClickMoverComponent::onSelectionUpdate(const SelectionSubject* subject) {
		this->m_selected = subject->selected;
	}

}
