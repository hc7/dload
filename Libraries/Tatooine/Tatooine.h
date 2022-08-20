#pragma once

#include <iostream>
#include "IPlanet.h"

class Tatooine : public IPlanet
{
public:
	Tatooine() = default;
	~Tatooine() = default;

	void greet() override;
	void hello(int val);
};
