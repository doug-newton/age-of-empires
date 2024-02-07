#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "click_collision_component.h"
#include "transform_component.h"
#include "camera_component.h"
#include "../entities/camera.h"
#include <iostream>

namespace aoe_engine {

	ClickCollisionComponent::ClickCollisionComponent() :
		Component("click_collision"),
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
			double left, right, top, bottom;
		} aabb;

		aabb.left = e_pos.x - e_size.x / 2;
		aabb.right = e_pos.x + e_size.x / 2;
		aabb.top = e_pos.y - e_size.y / 2;
		aabb.bottom = e_pos.y + e_size.y / 2;

		Camera* camera = Camera::getActiveCamera();

		void* p_transform = camera->findComponent("transform");
		TransformComponent* camera_transform = static_cast<TransformComponent*>(p_transform);

		void* p_camera = camera->findComponent("camera");
		CameraComponent* camera_cmp = static_cast<CameraComponent*>(p_camera);

		glm::vec2 camera_pos = camera_transform->getTranslation();
		glm::vec2 camera_scaling = camera_transform->getScaling();
		float ar = camera_cmp->getAspectRatio();

		struct {
			double x, y;
		} mouse_world_pos;

		mouse_world_pos.x = (event.x / event.screen_width - 0.5f) * camera_scaling.x * 2 + (camera_pos.x * camera_scaling.x);
		mouse_world_pos.y = (event.y / event.screen_height - 0.5f) * camera_scaling.y / ar * 2 - (camera_pos.y * camera_scaling.y / ar);

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
