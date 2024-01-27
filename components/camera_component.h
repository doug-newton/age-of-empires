#include "../core/component.h"
#include <vector>

namespace aoe_engine {

	class TransformComponent;
	class ShaderProgram;

	class CameraComponent : public Component {
	public:
		CameraComponent(std::vector<std::string> programNames);
		virtual ~CameraComponent();

		virtual bool onInit() override;
		virtual void onRender() override;

	private:
		TransformComponent* m_transform_component;
		std::vector<std::string> m_program_names;
		std::vector<ShaderProgram*> m_shader_programs;
	};

}