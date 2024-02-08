#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "click_collision_component.h"
#include "transform_component.h"
#include "view_component.h"
#include "../camera/camera.h"
#include <iostream>
#include "../camera/camera_system.h"

namespace aoe_engine {

	ClickCollisionComponent::ClickCollisionComponent() :
		Component("click_collision"),
		m_position(0.0f, 0.0f),
		m_size(1.0f, 1.0f) {
	}

	ClickCollisionComponent::~ClickCollisionComponent() {
	}

	bool ClickCollisionComponent::onInit() {
		subscribe("transform");
		return true;
	}

	void ClickCollisionComponent::onTransformUpdate(const TransformSubject* subject) {
		this->m_position = subject->translation;
		this->m_size = subject->scaling;
	}

	void ClickCollisionComponent::onMouseButtonEvent(const MouseButtonEvent& event) {
		struct {
			double left, right, top, bottom;
		} aabb;

		aabb.left = this->m_position.x - this->m_size.x / 2;
		aabb.right = this->m_position.x + this->m_size.x / 2;
		aabb.top = this->m_position.y - this->m_size.y / 2;
		aabb.bottom = this->m_position.y + this->m_size.y / 2;

		Camera* camera = CameraSystem::getActiveCamera();

		void* p_transform = camera->findComponent("transform");
		TransformComponent* camera_transform = static_cast<TransformComponent*>(p_transform);

		void* p_view = camera->findComponent("view");
		ViewComponent* view_cmp = static_cast<ViewComponent*>(p_view);

		glm::vec2 view_pos = camera_transform->translation;
		glm::vec2 view_scaling = camera_transform->scaling;
		float ar = view_cmp->getAspectRatio();

		struct {
			double x, y;
		} mouse_world_pos;

		mouse_world_pos.x = (event.x / event.screen_width - 0.5f) * view_scaling.x * 2 + (view_pos.x * view_scaling.x);
		mouse_world_pos.y = (event.y / event.screen_height - 0.5f) * view_scaling.y / ar * 2 - (view_pos.y * view_scaling.y / ar);

		if (mouse_world_pos.x < aabb.left) {
			return;
		}

		if (mouse_world_pos.x > aabb.right) {
			return;
		}

		if (mouse_world_pos.y < aabb.top) {
			return;
		}

		if (mouse_world_pos.y > aabb.bottom) {
			return;
		}

		std::cout << "click collision detected" << std::endl;
	}

}
