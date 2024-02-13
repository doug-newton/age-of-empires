#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "selection_component.h"
#include "../subjects/click_subject.h"
#include "../core/entity.h"

namespace aoe_engine {

	SelectionComponent::SelectionComponent() :
		Component("selection") {
	}

	SelectionComponent::~SelectionComponent() {
	}

	void SelectionComponent::onEntityRegistration() {
		this->registerSubject(this->getParent());
	}

	bool SelectionComponent::onInit() {
		subscribe("click");
		return true;
	}

	void SelectionComponent::onClickUpdate(const ClickSubject* subject) {
		if (subject->button == GLFW_MOUSE_BUTTON_LEFT && subject->action == GLFW_PRESS) {
			if (subject->aabb_clicked != this->selected) {
				this->selected = subject->aabb_clicked;
				publish();
			}
		}
	}

}
