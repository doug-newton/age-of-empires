#include "cursor_pos_binder_component.h"
#include "../core/entity.h"
#include "../camera/camera_system.h"
#include "../subjects/camera_info_subject.h"

namespace aoe_engine {

	CursorPosBinderComponent::CursorPosBinderComponent() :
		Component("cursor_pos_binder"),
		SetTransformSubject(),
		m_camera_pos(0.0f, 0.0f),
		m_camera_scaling(1.0f, 1.0f),
		m_camera_aspect_ratio(1.0f) {
	}

	CursorPosBinderComponent::~CursorPosBinderComponent() {
	}

	void CursorPosBinderComponent::onEntityRegistration() {
		this->registerSubject(this->getParent());
	}

	bool CursorPosBinderComponent::onInit() {
		CameraSystem::addCameraInfoSubscriber(this);
		return true;
	}

	void CursorPosBinderComponent::onCameraInfoUpdate(const CameraInfoSubject* subject) {
		this->m_camera_pos = subject->position;
		this->m_camera_scaling = subject->scaling;
		this->m_camera_aspect_ratio = subject->aspect_ratio;
	}

	void CursorPosBinderComponent::onMouseMoveEvent(const MouseMoveEvent& event) {

		struct {
			double x, y;
		} click_pos;

		click_pos.x = (event.x - event.screen_width / 2) / event.screen_width;
		click_pos.y = (event.screen_height / 2 - event.y) / event.screen_height;

		click_pos.x *= this->m_camera_scaling.x * 2;
		click_pos.y *= this->m_camera_scaling.y * 2;
		click_pos.y /= this->m_camera_aspect_ratio;

		click_pos.x += this->m_camera_pos.x;
		click_pos.y += this->m_camera_pos.y;

		this->translation.x = click_pos.x;
		this->translation.y = click_pos.y;

		publish();
	}

}
