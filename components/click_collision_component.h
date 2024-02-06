#pragma once

#include "../core/component.h"

namespace aoe_engine {

	class TransformComponent;

	class ClickCollisionComponent : public Component {

	public:

		ClickCollisionComponent();
		virtual ~ClickCollisionComponent();
		
		bool onInit() override;
		void onMouseButtonEvent(const MouseButtonEvent& event) override;

	private:

		TransformComponent* m_transform_component;

	};

}
