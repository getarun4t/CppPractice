#include "singleton.h"

Singleton& get_singleton()
{
	static Singleton single;
	std::cout << "Initializing with value: " << & single << std::endl;
	return single;
}
