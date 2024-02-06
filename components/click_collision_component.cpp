#include "click_collision_component.h"
#include "transform_component.h"
#include "../entities/camera.h"

namespace aoe_engine {

	ClickCollisionComponent::ClickCollisionComponent() :
		Component("click_collission"),
		m_transform_component(nullptr) {
	}

	ClickCollisionComponent::~ClickCollisionComponent() {
	}

	bool ClickCollisionComponent::onInit() {
		this->m_transform_component = getComponent<TransformComponent>("transform");

		if (this->m_transform_component == nullptr) {
			return false;
		}

		return true;
	}

	void ClickCollisionComponent::onMouseButtonEvent(int button, int action, int mods) {

	}

}
