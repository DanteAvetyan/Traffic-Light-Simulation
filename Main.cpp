#include "IntersectionManager.h"
#include "TrafficClass.h"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	IntersectionManager manager;
	manager.startSimulation(2); //How many times it loops through traffic

	std::cin.get();
	return 0;
}