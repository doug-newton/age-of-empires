#pragma once

#include "../core/entity.h"
#include "../components/transform_component.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class Camera : public Entity {

	public:

		Camera();
		Camera(float scaling, const glm::vec2& position);

		void onUpdate(float delta) override;
		void onRender() override;

		void activate();
		inline bool isActive();

	private:

		static Camera* s_current_camera;
		
	};

}