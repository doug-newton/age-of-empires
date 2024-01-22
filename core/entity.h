#include <map>
#include <string>

#include "component.h"
#include "component_exists_exception.h"

class Entity {
public:

	Entity();
	~Entity();
	void onInit();
	void onUpdate(float delta);
	void onRender();
	void onKeyEvent(int key, int scanCode, int action, int mods);

	void registerComponent(Component* component);
	Component* findComponent(const std::string& name);

private:

	std::map<std::string, Component*> m_components;


};