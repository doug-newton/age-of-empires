#pragma once

#include "../core/component.h"

namespace aoe_engine {

	class TransformComponent;

	class ClickCollisionComponent : public Component {

	public:

		ClickCollisionComponent();
		virtual ~ClickCollisionComponent();
		
		bool onInit() override;
		void onMouseButtonEvent(int button, int action, int mods) override;

	private:

		TransformComponent* m_transform_component;

	};

}
