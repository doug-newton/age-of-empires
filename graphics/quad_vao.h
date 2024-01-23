#pragma once

#include "vao.h"

class QuadVao : public Vao {
public:
	QuadVao();
	virtual ~QuadVao();

	virtual bool onInit();
};
