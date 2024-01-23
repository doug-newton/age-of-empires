#include "../core/component.h"

class ShaderProgram;
class Vao;

class QuadComponent : public Component {
public:
	QuadComponent();
	~QuadComponent();

	virtual bool onInit() override;
	virtual void onRender() override;

private:

	ShaderProgram* m_shader_program;
	Vao* m_vao;

};
