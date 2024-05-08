#pragma once

#include "vao.h"
#include <vector>
#include <string>

namespace aoe_engine {

	class CustomVao : public Vao {
	public:

		CustomVao(const std::string& name);
		virtual ~CustomVao();
		virtual bool onInit() override;

	private:

		std::string m_name;

		void create(std::vector<int>& attributes, std::vector<GLfloat>& vertices, std::vector<GLuint>& elements);
	};
}
