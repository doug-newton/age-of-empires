#include "camera.h"
#include "../components/wasd_component.h"
#include "../components/motion_component.h"
#include "../components/transform_component.h"
#include "../components/camera_component.h"

namespace aoe_engine {

	Camera::Camera() :
		Entity() {
		TransformComponent* tc = new TransformComponent();
		tc->setScaling(16.0f, 16.0f);
		this->registerComponent(tc);
		this->registerComponent(new MotionComponent());
		this->registerComponent(new WASDComponent());
		this->registerComponent(new CameraComponent({ "transform", "texture", "animated_texture" }));
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
		this->registerComponent(new CameraComponent({ "transform", "texture", "animated_texture" }));
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
		s_current_camera = this;
	}

	bool Camera::isActive() {
		return this == s_current_camera;
	}

	Camera* Camera::s_current_camera = nullptr;

}