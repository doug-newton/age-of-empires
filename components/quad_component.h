#include "../core/component.h"

class ShaderProgram;
class Vao;
class TransformComponent;

class QuadComponent : public Component {
public:
	QuadComponent();
	~QuadComponent();

	virtual bool onInit() override;
	virtual void onRender() override;

private:

	ShaderProgram* m_shader_program;
	Vao* m_vao;
	TransformComponent* m_transform_component;

};
