#include "../core/component.h"
#include <vector>
#include <glm/glm.hpp>

namespace aoe_engine {

	class ShaderProgram;

	class CameraComponent : public Component {
	public:
		CameraComponent(std::vector<std::string> programNames);
		virtual ~CameraComponent();

		virtual bool onInit() override;
		virtual void onRender() override;
		virtual void onWindowResize(int width, int height);
		void onTransformUpdate(const TransformSubject* subject);
		float getAspectRatio();

	private:
		std::vector<std::string> m_program_names;
		std::vector<ShaderProgram*> m_shader_programs;
		float m_aspect_ratio;
		glm::mat4 m_view;
	};

}