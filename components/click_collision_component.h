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

	private:

		glm::vec2 m_position;
		glm::vec2 m_size;

	};

}
