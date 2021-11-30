#include <chrono>
#include <iostream>
#include <type_traits>
#include "raylib.h"
#include "include/engine/time.h"
#include "include/engine/Clock.h"
#include "include/engine/Game.h"
#include "include/engine/Scene.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
using namespace Catcher::Survivor;

Game::Game(Scene *initialScene)
{
    clock = Clock();
    shouldRun = false;
    timePerUpdate = 1.0;
    currentScene = initialScene;
}

void Game::run()
{
    // Initialization ----------------------------------------------------------
    shouldRun = true;

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Survivor");
    SetWindowState(FLAG_WINDOW_ALWAYS_RUN);
    SetExitKey(KEY_ESCAPE);

    int framesElapsed = 0;
    long int gameStart = timeSinceEpoch();

    // Game Loop ---------------------------------------------------------------
    while(isRunning())
    {
        long int frameStart = timeSinceEpoch();
        clock.tick();

        // Input Handling ------------------------------------------------------
        currentScene->handleInput();

        // Update Cycles -------------------------------------------------------
        currentScene->update();
        while(clock.getLag() >= timePerUpdate)
        {
            currentScene->fixedUpdate();
            clock.updateTick(timePerUpdate);
        }
        currentScene->lateUpdate();

        // Rendering -----------------------------------------------------------
        BeginDrawing();
        currentScene->draw();
        currentScene->drawGui();
        EndDrawing();

        // Clamp The FPS -------------------------------------------------------
        // Locks the fps to roughly 60 FPS
        long int toSleep = (frameStart + 16 - timeSinceEpoch()) * 1000;
        usleep(static_cast<int>(toSleep));

        // Debugging frames per second
        // TODO: Put this is a better place, maybe the Clock class
        framesElapsed += 1;
        if(framesElapsed % 100 == 0)
        {
            long int msElapsed = timeSinceEpoch() - gameStart;
            long double framesPerSecond = (static_cast<long double>(framesElapsed) / static_cast<long double>(msElapsed)) * 1000;
            cout << framesPerSecond << " fps" << endl;
        }
    }

    // Cleanup -----------------------------------------------------------------
    CloseWindow();
}

void Game::stop()
{
    shouldRun = false;
}

bool Game::isRunning()
{
    return shouldRun && !WindowShouldClose();
}
