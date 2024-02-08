#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "click_collision_component.h"
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

	void ClickCollisionComponent::onEntityRegistration() {
		registerSubject(this->getParent());
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
		aabb aabb;

		aabb.left = this->m_position.x - this->m_size.x / 2;
		aabb.right = this->m_position.x + this->m_size.x / 2;
		aabb.top = this->m_position.y - this->m_size.y / 2;
		aabb.bottom = this->m_position.y + this->m_size.y / 2;

		click_pos click_pos;

		float ar = this->m_camera_aspect_ratio;

		click_pos.x = (event.x - event.screen_width / 2) / event.screen_width;
		click_pos.y = (event.y - event.screen_height / 2) / event.screen_height;

		click_pos.x *= this->m_camera_scaling.x * 2;
		click_pos.y *= this->m_camera_scaling.y * 2;
		click_pos.y /= ar;

		click_pos.x += this->m_camera_pos.x;
		click_pos.y -= this->m_camera_pos.y;

		this->aabb_clicked = aabbClicked(aabb, click_pos);
		this->button = event.button;
		this->action = event.action;
		this->mods = event.mods;
		this->world_x = click_pos.x;
		this->world_y = click_pos.y;

		publish();
	}

	bool ClickCollisionComponent::aabbClicked(const aabb& aabb, const click_pos& click_pos) {
		if (click_pos.x < aabb.left) return false;
		if (click_pos.x > aabb.right) return false;
		if (click_pos.y < aabb.top) return false;
		if (click_pos.y > aabb.bottom) return false;
		return true;
	}

}
