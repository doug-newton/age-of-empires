#pragma once

#include "../core/game_object.h"

namespace aoe_engine {

	class Villager : public GameObject {

	public:

		virtual ~Villager();
		virtual bool onInit() override;
		virtual void onUpdate(float delta) override;
		virtual void onRender() override;

		virtual void onWindowResize(int width, int height) override;
		virtual void onKeyEvent(int key, int scanCode, int action, int mods) override;
		virtual void onMouseButtonEvent(const MouseButtonEvent& event) override;
		virtual void onMouseMoveEvent(const MouseMoveEvent& event) override;

	};

}
