#include <chrono>
#include <iostream>
#include <type_traits>
#include "include/engine/Clock.h"
#include "include/engine/Game.h"
#include "include/engine/time.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
using namespace Catcher::Survivor;

Game::Game()
{
    clock = Clock();
    running = false;
    timePerUpdate = 1.0;
}

void Game::run()
{
    running = true;

    int framesElapsed = 0;
    long int gameStart = timeSinceEpoch();

    while(running)
    {
        long int frameStart = timeSinceEpoch();

        clock.tick();

        while(clock.getLag() >= timePerUpdate)
        {
            // update(): TODO
            clock.updateTick(timePerUpdate);
        }

        // render(): TODO

        long int toSleep = (frameStart + 16 - timeSinceEpoch()) * 1000;
        usleep(static_cast<int>(toSleep));

        // Debugging frames per second...
        framesElapsed += 1;
        if(framesElapsed % 100 == 0)
        {
            long int msElapsed = timeSinceEpoch() - gameStart;
            long double framesPerSecond = (static_cast<long double>(framesElapsed) / static_cast<long double>(msElapsed)) * 1000;
            cout << framesPerSecond << " fps" << endl;
        }
    }
}

void Game::stop()
{
    running = false;
}
