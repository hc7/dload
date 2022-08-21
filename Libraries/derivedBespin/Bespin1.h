#pragma once

#include <iostream>
#include "Bespin.h"
#include "Bespin1.h"
#include "IPlanet.h"

class Bespin1 : public Bespin
{
public:
	Bespin1() = default;
	~Bespin1() = default;

	void greet() override;
};
