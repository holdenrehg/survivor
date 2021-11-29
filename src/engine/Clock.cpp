#include "include/engine/Clock.h"

using namespace Catcher::Survivor;

Clock::Clock()
{
    resetTime();
}

double Clock::getCurrentTime()
{
    return 0;  // TODO
}

double Clock::getLag()
{
    return lag;
}

void Clock::updateTick(double timePerUpdate)
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
    double currentTime = getCurrentTime();
    double elapsedTime = currentTime - previousTime;

    previousTime = currentTime;
    lag += elapsedTime;
}
