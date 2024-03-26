#ifndef INTERSECTIONMANAGER_H
#define INTERSECTIONMANAGER_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include "LinkedQueue.h"

class IntersectionManager
{
private:
	std::map<char, LinkedQueue<int>> vehiclesByDirection;
	int randomAmountNS = rand() % 10 + 1;
	int randomAmountEW = rand() % 10 + 1;
	int totalTime;

	const int GREEN_DURATION = 5;
	const int YELLOW_DURATION = 2;
	const int RED_DURATION = 5;

	enum class LightState { RED, GREEN, YELLOW };
	LightState currentState = LightState::GREEN;
	int elapsedTime = 0;

public:

	IntersectionManager();
	~IntersectionManager();
	void startSimulation(int loopAmount);
	void processVehicles(char direction);
	void addVehiclesRandomly();
	void processTraffic();
	void printResults();

};

#endif // !INTERSECTIONMANAGER_H

