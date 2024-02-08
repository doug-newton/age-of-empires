#include "camera.h"
#include "../components/wasd_component.h"
#include "../components/motion_component.h"
#include "../components/transform_component.h"
#include "../components/view_component.h"
#include "camera_system.h"

namespace aoe_engine {

	Camera::Camera() :
		Entity() {
		TransformComponent* tc = new TransformComponent();
		tc->setScaling(16.0f, 16.0f);
		this->registerComponent(tc);
		this->registerComponent(new MotionComponent());
		this->registerComponent(new WASDComponent());
		this->registerComponent(new ViewComponent({ "transform", "texture", "animated_texture" }));
		CameraSystem::registerCamera(this);
		this->activate();
	}

	Camera::Camera(float scaling, const glm::vec2& position) :
		Entity() {
		TransformComponent* tc = new TransformComponent();
		tc->setScaling(scaling, scaling);
		tc->setTranslation(position.x, position.y);
		this->registerComponent(tc);
		this->registerComponent(new MotionComponent());
		this->registerComponent(new WASDComponent());
		this->registerComponent(new ViewComponent({ "transform", "texture", "animated_texture" }));
		CameraSystem::registerCamera(this);
		this->activate();
	}

	void Camera::onRender() {
		if (!isActive()) return;
		Entity::onRender();
	}

	void Camera::onUpdate(float delta) {
		if (!isActive()) return;
		Entity::onUpdate(delta);
	}

	void Camera::activate() {
		CameraSystem::s_active_camera = this;
	}

	bool Camera::isActive() {
		return this == CameraSystem::s_active_camera;
	}

}