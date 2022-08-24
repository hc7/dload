#pragma once

#include <iostream>
#include "Bespin.h"

class BDerived : public IPlanet
{
	IPlanet *own_class;
public:
	BDerived() = default;
	virtual ~BDerived() = default;

	virtual void greet() override;
	virtual void hello(IPlanet *iface) override;
};
