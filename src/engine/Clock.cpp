#include "include/engine/time.h"
#include "include/engine/Clock.h"

using namespace Catcher::Survivor;

Clock::Clock()
{
    resetTime();
}

long int Clock::getCurrentTime()
{
    return timeSinceEpoch();
}

long int Clock::getLag()
{
    return lag;
}

void Clock::updateTick(long int timePerUpdate)
{
    lag -= timePerUpdate;
}

void Clock::resetTime()
{
    lag = 0;
    previousTime = getCurrentTime();
}

void Clock::tick()
{
    long int currentTime = getCurrentTime();
    long int elapsedTime = currentTime - previousTime;

    previousTime = currentTime;
    lag += elapsedTime;
}
