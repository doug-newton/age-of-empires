#pragma once

#include "vao.h"

Vao::Vao() :
	m_id(0) {
}

Vao::~Vao() {
	if (this->m_id == 0) {
		return;
	}
	glDeleteVertexArrays(1, &this->m_id);
}
