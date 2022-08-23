#include <iostream>
#include <string>
#include <memory>
#include "DLLoader.h"
#include "Bespin.h"
#include "IPlanet.h"

using namespace std;

#ifdef WIN32
static const std::string bespinLibPath = "derivedBespin.dll";
static const std::string tatooineLibPath = "Tatooine.dll";
#endif
#ifdef __linux__
static const std::string bespinLibPath = "./libBespin.so";
static const std::string tatooineLibPath = "./libTatooine.so";
#endif
#ifdef __APPLE__
static const std::string bespinLibPath = "./libBespin.dylib";
static const std::string tatooineLibPath = "./libTatooine.dylib";
#endif



#if defined(__linux__) || defined(__APPLE__)
extern "C"
{
	Bespin *allocator()
	{
		return new Bespin();
	}

	void deleter(Bespin *ptr)
	{
		delete ptr;
	}
}
#endif

#ifdef WIN32
extern "C"
{
	__declspec (dllexport) Bespin *allocator()
	{
		return new Bespin();
	}

	__declspec (dllexport) void deleter(Bespin *ptr)
	{
		delete ptr;
	}
}
#endif

void Bespin::greet()
{
	std::cout << "Greetings from Bespin !" << std::endl;
}

void Bespin::hello(int val)
{
	std::cout << "Hello from Bespin !" << val << std::endl;
}

/*
** Using the smart pointer directly in an inner function because
** the reference to its destructor contained in the dll is lost before
** going out of the caller function's scope.
*/
void greetFromAPlanet(dlloader::DLLoader<IPlanet>& dlloader)
{
	std::shared_ptr<IPlanet> planet = dlloader.DLGetInstance();

	planet->greet();
}

void helloFromAPlanet(dlloader::DLLoader<IPlanet> &dlloader)
{
	std::shared_ptr<IPlanet> planet = dlloader.DLGetInstance();

	planet->hello(1);
}

void greet(const std::string& path)
{
	dlloader::DLLoader<IPlanet> dlloader(path);

	std::cout << "Loading " << path << std::endl;
	dlloader.DLOpenLib();

	greetFromAPlanet(dlloader);

	std::cout << "Unloading " << path << std::endl;
	dlloader.DLCloseLib();
}

void hello(const std::string &path)
{
	dlloader::DLLoader<IPlanet> dlloader(path);

	std::cout << "Loading " << path << std::endl;
	dlloader.DLOpenLib();

	helloFromAPlanet(dlloader);

	std::cout << "Unloading " << path << std::endl;
	dlloader.DLCloseLib();
}

int main()
{
	greet(tatooineLibPath);
	greet(bespinLibPath);

	hello(tatooineLibPath);
	hello(bespinLibPath);

	return 0;
}
