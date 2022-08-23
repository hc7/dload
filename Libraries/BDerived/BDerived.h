#pragma once

#include <iostream>
#include "Bespin.h"

class BDerived : public Bespin
{
public:
	BDerived() : Bespin() {}
	virtual ~BDerived() = default;

	virtual void greet() override;
};
