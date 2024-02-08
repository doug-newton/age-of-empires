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
		m_size(1.0f, 1.0f),
		m_camera_pos(0.0f, 0.0f),
		m_camera_scaling(1.0f, 1.0f),
		m_camera_aspect_ratio(1.0f) {
	}

	ClickCollisionComponent::~ClickCollisionComponent() {
	}

	bool ClickCollisionComponent::onInit() {
		subscribe("transform");
		CameraSystem::addCameraInfoSubscriber(this);
		return true;
	}

	void ClickCollisionComponent::onTransformUpdate(const TransformSubject* subject) {
		this->m_position = subject->translation;
		this->m_size = subject->scaling;
	}

	void ClickCollisionComponent::onCameraInfoUpdate(const CameraInfoSubject* subject) {
		this->m_camera_pos = subject->position;
		this->m_camera_scaling = subject->scaling;
		this->m_camera_aspect_ratio = subject->aspect_ratio;
	}

	void ClickCollisionComponent::onMouseButtonEvent(const MouseButtonEvent& event) {
		struct {
			double left, right, top, bottom;
		} aabb;

		aabb.left = this->m_position.x - this->m_size.x / 2;
		aabb.right = this->m_position.x + this->m_size.x / 2;
		aabb.top = this->m_position.y - this->m_size.y / 2;
		aabb.bottom = this->m_position.y + this->m_size.y / 2;

		float ar = this->m_camera_aspect_ratio;

		struct {
			double x, y;
		} mouse_world_pos;

		mouse_world_pos.x = (event.x / event.screen_width - 0.5f) * this->m_camera_scaling.x * 2 + (this->m_camera_pos.x * this->m_camera_scaling.x);
		mouse_world_pos.y = (event.y / event.screen_height - 0.5f) * this->m_camera_scaling.y / ar * 2 - (this->m_camera_pos.y * this->m_camera_scaling.y / ar);

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
