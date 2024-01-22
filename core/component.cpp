#include "component.h"
#include "entity.h"

Component::Component(const std::string& name) :
	m_parent(nullptr),
	m_name(name)
{
}

Component::~Component() {
}

bool Component::onInit() {
	return true;
}

void Component::onUpdate(float delta) {
}

void Component::onRender() {
}

void Component::onKeyEvent(int key, int scancode, int action, int mods) {
}

const std::string& Component::getName() {
	return this->m_name;
}

void Component::setParent(Entity* parent) {
	this->m_parent = parent;
}