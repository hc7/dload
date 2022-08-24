#include "BDerived.h"

#if defined(__linux__) || defined(__APPLE__)
extern "C"
{
	BDerived *allocator()
	{
		return new BDerived();
	}

	void deleter(BDerived *ptr)
	{
		delete ptr;
	}
}
#endif

#ifdef WIN32
extern "C"
{
	__declspec (dllexport) BDerived *allocator()
	{
		return new BDerived();
	}

	__declspec (dllexport) void deleter(BDerived *ptr)
	{
		delete ptr;
	}
}
#endif

void BDerived::greet()
{
	std::cout << "Greetings from BDerived !" << std::endl;
}

void BDerived::hello(IPlanet *iface)
{
	std::cout << "calling greet() function from IPlanet" << std::endl;
	own_class = iface;
	own_class->greet();
}
