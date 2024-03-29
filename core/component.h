#pragma once

#include <string>
#include "resource_manager.h"
#include "../events/mouse_button_event.h"
#include "../events/mouse_move_event.h"
#include "subscriber.h"

namespace aoe_engine {

	class Message;
	class Entity;
	class ChangeMotionMessage;

	class Component: public Subscriber {
	public:

		Component(const std::string& name);
		~Component();

		virtual bool onInit();
		virtual void onUpdate(float delta);
		virtual void onRender();

		virtual void onWindowResize(int width, int height);
		virtual void onKeyEvent(int key, int scancode, int action, int mods);
		virtual void onMouseButtonEvent(const MouseButtonEvent& event);
		virtual void onMouseMoveEvent(const MouseMoveEvent& event);

		const std::string& getName();
		void setParent(Entity* parent);
		virtual void onEntityRegistration();

		void subscribe(const std::string& name);

	protected:

		template <class ComponentType>
		ComponentType* getComponent(const std::string& name);

		ShaderProgram* getShaderProgram(const std::string& name);
		Vao* getVao(const std::string& name);
		Texture* getTexture(const std::string& name);

		void sendMessage(Message* message);

		Entity* getParent();

	private:

		ResourceManager* getResourceManager();
		Component* findComponent(const std::string& name);

		Entity* m_parent;
		std::string m_name;
	};

	template <class ComponentType>
	ComponentType* Component::getComponent(const std::string& name) {
		static_assert(std::is_base_of<Component, ComponentType>::value, "ComponentType must be derived from Component");

		void* component = findComponent(name);

		if (component == nullptr) {
			return nullptr;
		}

		return static_cast<ComponentType*>(component);
	}

}
