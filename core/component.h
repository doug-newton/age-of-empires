#pragma once

#include <string>
#include "resource_manager.h"

class Entity;

class Component {
public:

	Component(const std::string& name);
	~Component();

	virtual bool onInit();
	virtual void onUpdate(float delta);
	virtual void onRender();
	virtual void onKeyEvent(int key, int scancode, int action, int mods);

	const std::string& getName();
	void setParent(Entity* parent);

protected:
	ResourceManager* getResourceManager();
	Component* findComponent(const std::string& name);

private:

	Entity* m_parent;
	std::string m_name;
};
