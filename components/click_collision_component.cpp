#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "click_collision_component.h"
#include "transform_component.h"
#include "../entities/camera.h"
#include <iostream>

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

	void ClickCollisionComponent::onMouseButtonEvent(const MouseButtonEvent& event) {
		glm::vec2 e_pos = this->m_transform_component->getTranslation();
		glm::vec2 e_size = this->m_transform_component->getScaling();

		struct {
			float left, right, top, bottom;
		} aabb;

		aabb.left = e_pos.x - e_size.x / 2;
		aabb.right = e_pos.x + e_size.x / 2;
		aabb.top = e_pos.y - e_size.y / 2;
		aabb.bottom = e_pos.y + e_size.y / 2;
	}

}
