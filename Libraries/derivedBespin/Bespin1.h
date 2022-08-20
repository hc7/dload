#pragma once

#include <iostream>
#include "IPlanet.h"

class Bespin1 : public IPlanet
{
public:
	Bespin1() = default;
	~Bespin1() = default;

	void greet() override;
	void hello(int val) override;
};
