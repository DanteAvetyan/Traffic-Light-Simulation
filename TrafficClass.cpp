#include "TrafficClass.h"
#include "IntersectionManager.h"

IntersectionManager* u = new IntersectionManager();

void TrafficClass::update()
{
    elapsedTime++;
    switch (currentState) 
    {
    case LightState::GREEN:
        if (elapsedTime >= GREEN_DURATION) 
        {
            currentState = LightState::YELLOW;
            elapsedTime = 0;
        }
        break;
    case LightState::YELLOW:
        if (elapsedTime >= YELLOW_DURATION) 
        {
            currentState = LightState::RED;
            elapsedTime = 0;
        }
        break;
    case LightState::RED:
        if (elapsedTime >= RED_DURATION) 
        {
            currentState = LightState::GREEN;
            elapsedTime = 0;
            nsActive = !nsActive;
        }
        break;
    }
}
