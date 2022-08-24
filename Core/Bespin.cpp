#include "Bespin.h"


void Bespin::greet()
{
	std::cout << "Greetings from Bespin !!!!" << std::endl;
}

void Bespin::hello(IPlanet *iface)
{
	std::cout << "Hello from Bespin !" << iface << std::endl;
}
