#pragma once

#include <map>
#include <string>

#include "component.h"
#include "component_exists_exception.h"
#include "../events/mouse_button_event.h"
#include "subject_registry.h"

namespace aoe_engine {

	class Game;

	class Entity: public SubjectRegistry {
	public:

		Entity();
		~Entity();
		virtual bool onInit();
		virtual void onUpdate(float delta);
		virtual void onRender();

		virtual void onWindowResize(int width, int height);
		virtual void onKeyEvent(int key, int scanCode, int action, int mods);
		virtual void onMouseButtonEvent(const MouseButtonEvent& event);
		virtual void onMouseMoveEvent(const MouseMoveEvent& event);

		void registerComponent(Component* component);
		Component* findComponent(const std::string& name);
		void setGame(Game* game);
		Game* getGame();

		void sendMessage(Message*);

		virtual void registerSubject(const std::string& name, Subject* subject) override;
		virtual Subject* getSubject(const std::string&) override;

	private:

		Game* m_game;
		std::map<std::string, Component*> m_components;

		std::map<std::string, Subject*> m_subjects;


	};

}