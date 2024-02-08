#include "../core/component.h"
#include "../subjects/view_subject.h"
#include <vector>
#include <glm/glm.hpp>

namespace aoe_engine {

	class ShaderProgram;

	class ViewComponent : public Component, public ViewSubject {
	public:
		ViewComponent(std::vector<std::string> programNames);
		virtual ~ViewComponent();

		void onEntityRegistration() override;
		virtual bool onInit() override;
		virtual void onRender() override;
		virtual void onWindowResize(int width, int height);
		void onTransformUpdate(const TransformSubject* subject);
		float getAspectRatio();

	private:
		std::vector<std::string> m_program_names;
		std::vector<ShaderProgram*> m_shader_programs;
		glm::mat4 m_view;
	};

}