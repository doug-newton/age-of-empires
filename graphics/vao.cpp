#pragma once

#include "vao.h"

namespace aoe_engine {

	Vao::Vao() :
		m_id(0),
		m_num_elements(0) {
	}

	Vao::~Vao() {
		if (this->m_id == 0) {
			return;
		}
		glDeleteVertexArrays(1, &this->m_id);
	}

	GLuint Vao::getID() {
		return this->m_id;
	}

	void Vao::bind() {
		glBindVertexArray(this->m_id);
	}

	void Vao::render() {
		glBindVertexArray(this->m_id);
		glDrawElements(GL_TRIANGLES, this->m_num_elements, GL_UNSIGNED_INT, (GLvoid*)0);
	}

}
