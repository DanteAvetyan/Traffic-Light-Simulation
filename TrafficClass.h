#ifndef TRAFFICLASS_H
#define TRAFFICLASS_H

#include <iostream>

class TrafficClass
{
private:
	int elapsedTime = 0;
	enum class LightState { RED, GREEN, YELLOW };
	LightState currentState = LightState::GREEN;

	const int GREEN_DURATION = 5;
	const int YELLOW_DURATION = 2;
	const int RED_DURATION = 5;

	bool nsActive = true;
	const int CYCLE_DURATION = 30;
public:

	void update();
	bool isNSActive() const { return nsActive; }
};

#endif // !TRAFFICLASS_H
