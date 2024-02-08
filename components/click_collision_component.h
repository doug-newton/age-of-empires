#pragma once

#include "../core/component.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class ClickCollisionComponent : public Component {

	public:

		ClickCollisionComponent();
		virtual ~ClickCollisionComponent();
		
		bool onInit() override;
		void onMouseButtonEvent(const MouseButtonEvent& event) override;
		void onTransformUpdate(const TransformSubject* subject) override;
		void onCameraInfoUpdate(const CameraInfoSubject* subject) override;

	private:

		glm::vec2 m_position;
		glm::vec2 m_size;

		glm::vec2 m_camera_pos;
		glm::vec2 m_camera_scaling;
		float m_camera_aspect_ratio;

		struct aabb {
			double left, right, top, bottom;
		};

		struct click_pos {
			double x, y;
		};

		bool aabbClicked(const aabb& aabb, const click_pos& click_pos);

	};

}
