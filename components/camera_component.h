#include "../core/component.h"

namespace aoe_engine {

	class TransformComponent;
	class ShaderProgram;

	class CameraComponent : public Component {
	public:
		CameraComponent();
		virtual ~CameraComponent();

		virtual bool onInit() override;
		virtual void onRender() override;

	public:
		TransformComponent* m_transform_component;
		ShaderProgram* m_transform_shader_program;
	};

}