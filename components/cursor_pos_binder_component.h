#pragma once

#include "../core/component.h"
#include "../subjects/set_transform_subject.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class CursorPosBinderComponent : public Component, public SetTransformSubject {

	public:

		CursorPosBinderComponent();
		virtual ~CursorPosBinderComponent();

		void onEntityRegistration() override;
		bool onInit() override;

		void onCameraInfoUpdate(const CameraInfoSubject* subject) override;
		void onMouseMoveEvent(const MouseMoveEvent& event) override;

	private:
		glm::vec2 m_camera_pos;
		glm::vec2 m_camera_scaling;
		float m_camera_aspect_ratio;

	};

}
