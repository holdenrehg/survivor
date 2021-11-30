#include <chrono>
#include <iostream>
#include <type_traits>
#include "raylib.h"
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

typedef enum Screen { TITLE, GAMEPLAY, ENDING } Screen;

Game::Game()
{
    clock = Clock();
    running = false;
    timePerUpdate = 1.0;
}

void Game::run()
{
    running = true;

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    int framesElapsed = 0;
    long int gameStart = timeSinceEpoch();

    while(running)
    {
        long int frameStart = timeSinceEpoch();

        clock.tick();

        update();
        while(clock.getLag() >= timePerUpdate)
        {
            fixedUpdate();
            clock.updateTick(timePerUpdate);
        }
        lateUpdate();

        // Draw to the window
        draw();
        drawGui();

        // Lock the fps to roughly 60 FPS
        long int toSleep = (frameStart + 16 - timeSinceEpoch()) * 1000;
        usleep(static_cast<int>(toSleep));

        // Debugging frames per second
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

void Game::fixedUpdate()
{
    //
}

void Game::lateUpdate()
{
    //
}

void Game::update()
{
    //
}

void Game::draw()
{
    //
}

void Game::drawGui()
{
    //
}
