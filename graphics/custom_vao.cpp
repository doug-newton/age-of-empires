#include "custom_vao.h"
#include <sstream>
#include <fstream>

namespace aoe_engine {

	CustomVao::CustomVao(const std::string& name)
		:
		m_name(name)
	{
	}

	CustomVao::~CustomVao() {
	}

	template<typename T>
	void read_into(std::vector<T>& target, const std::string& line) {
		std::stringstream source(line);
		T value;
		while (source >> value) {
			target.push_back(value);
		}
	}

	bool CustomVao::onInit() {

		std::ifstream file("res/vaos/" + m_name + ".vao");

		std::vector<int> attributes;
		std::vector<GLfloat> vertices;
		std::vector<GLuint> elements;

		enum {
			UNDEFINED,
			ATTRIBUTES,
			VERTICES,
			ELEMENTS
		} section = UNDEFINED;

		std::string line;

		while (std::getline(file, line)) {

			if (line.length() == 0) {
				continue;
			}

			switch (line[0]) {
			case 'a': section = ATTRIBUTES; break;
			case 'v': section = VERTICES; break;
			case 'e': section = ELEMENTS; break;
			default: break;
			}

			switch (section) {

			case ATTRIBUTES:
				read_into<int>(attributes, line);
				break;

			case VERTICES:
				read_into<GLfloat>(vertices, line);
				break;

			case ELEMENTS:
				read_into<GLuint>(elements, line);
				break;

			default:
				break;
			}

		}

		file.close();

		create(attributes, vertices, elements);

		return true;
	}

	void CustomVao::create(std::vector<int>& attributes, std::vector<GLfloat>& vertices, std::vector<GLuint>& elements) {
		glGenVertexArrays(1, &this->m_id);
		glBindVertexArray(this->m_id);

		//	vertices

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

		//	attribute pointers

		int vertex_width = 0;

		for (int attr_size : attributes) {
			vertex_width += attr_size;
		}

		int attr_index = 0;
		int offset = 0;

		for (int attr_size : attributes) {

			glVertexAttribPointer(attr_index, attr_size, GL_FLOAT, GL_FALSE, vertex_width * sizeof(GLfloat), (GLvoid*)(offset * sizeof(GLfloat)));
			glEnableVertexAttribArray(attr_index);

			offset += attr_size;
			attr_index++;
		}

		//	elements

		this->m_num_elements = elements.size();

		GLuint ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(GLuint), &elements[0], GL_STATIC_DRAW);

		glBindVertexArray(0);
	}

}