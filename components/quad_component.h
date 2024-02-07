#include "../core/component.h"
#include <glm/glm.hpp>

namespace aoe_engine {

	class ShaderProgram;
	class Vao;

	class QuadComponent : public Component {
	public:
		QuadComponent();
		~QuadComponent();

		virtual bool onInit() override;
		virtual void onRender() override;
		void onTransformUpdate(const TransformSubject* subject);

	private:

		ShaderProgram* m_shader_program;
		Vao* m_vao;
		glm::mat4 m_model;

	};

}
