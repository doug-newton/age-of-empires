#pragma once

#include "../core/component.h"

class MotionComponent;

class WASDComponent : public Component {
public:
	WASDComponent();
	virtual ~WASDComponent();

	virtual bool onInit() override;
	virtual void onKeyEvent(int key, int scanCode, int action, int mods) override;

private:
	float m_speed;
	MotionComponent* m_motion_component;
};

