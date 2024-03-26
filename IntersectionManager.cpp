#include "IntersectionManager.h"
#include "TrafficClass.h"

TrafficClass* u;

IntersectionManager::IntersectionManager()
{
	u = new TrafficClass();
}

IntersectionManager::~IntersectionManager()
{
	delete u;
}

void IntersectionManager::startSimulation(int loopAmount)
{
	totalTime = 30 * loopAmount;
	vehiclesByDirection['n'] = LinkedQueue<int>();
	vehiclesByDirection['s'] = LinkedQueue<int>();
	vehiclesByDirection['e'] = LinkedQueue<int>();
	vehiclesByDirection['w'] = LinkedQueue<int>();
	for (int currentTime = 0; currentTime < totalTime; ++currentTime)
	{
		addVehiclesRandomly();
		processTraffic();

		u->update();
	}

	printResults();
}

void IntersectionManager::addVehiclesRandomly()
{
	vehiclesByDirection['n'].enqueue(randomAmountNS);
	vehiclesByDirection['s'].enqueue(randomAmountNS);
	vehiclesByDirection['e'].enqueue(randomAmountEW);
	vehiclesByDirection['w'].enqueue(randomAmountEW);
	std::cout << "Added vehicles to queue for all sides." << std::endl;
}

void IntersectionManager::processVehicles(char direction)
{
	if (!vehiclesByDirection[direction].isEmpty())
	{
		vehiclesByDirection[direction].dequeue();
		std::cout << "Vehicle passed from direction: " << direction << std::endl;
	}
}

void IntersectionManager::processTraffic()
{
	if (!u->isNSActive()) 
	{
		processVehicles('n');
		processVehicles('s');
	}
	else 
	{
		processVehicles('e');
		processVehicles('w');
	}
}

void IntersectionManager::printResults()
{
	std::cout << "Total number of vehicles that passed in the north light after " << totalTime << " seconds: " << vehiclesByDirection['n'].getSize() << std::endl;
	std::cout << "Total number of vehicles that passed in the south light after " << totalTime << " seconds: " << vehiclesByDirection['s'].getSize() << std::endl;
	std::cout << "Total number of vehicles that passed in the east light after " << totalTime << " seconds: " << vehiclesByDirection['e'].getSize() << std::endl;
	std::cout << "Total number of vehicles that passed in the west light after " << totalTime << " seconds: " << vehiclesByDirection['w'].getSize() << std::endl;
}
