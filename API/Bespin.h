#pragma once

#include <iostream>
#include "IPlanet.h"

class Bespin : public IPlanet
{
public:
	Bespin() = default;
	virtual ~Bespin() = default;

	virtual void greet() override;
	virtual void hello(int val) override;
};
