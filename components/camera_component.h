#include "../core/component.h"

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