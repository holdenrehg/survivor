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
    timePerUpdate = 20; // ms
    currentScene = initialScene;
}

Game::~Game()
{
    delete currentScene;
}

void Game::run()
{
    // Initialization ----------------------------------------------------------
    shouldRun = true;

    const int screenWidth = 1920;
    const int screenHeight = 1280;
    const int targetWidth = 240;
    const int targetHeight = 160;

    InitWindow(screenWidth, screenHeight, "Survivor");
    SetWindowState(FLAG_WINDOW_ALWAYS_RUN | FLAG_WINDOW_RESIZABLE);
    SetExitKey(KEY_ESCAPE);

    RenderTexture2D target = LoadRenderTexture(targetWidth, targetHeight);
    Rectangle source = {0, (float) -targetHeight, (float) targetWidth, (float) -targetHeight}; // OpenGL coordinates are inverted
    Rectangle dest = {0, 0, (float) screenWidth, (float) screenHeight};

    int framesElapsed = 0;
    long int gameStart = timeSinceEpoch();

    // Game Loop ---------------------------------------------------------------
    while(isRunning())
    {
        long int frameStart = timeSinceEpoch();
        clock.tick();

        // Window Size Handling ------------------------------------------------
        // Maintain the same aspect ratio if the window is resized
        if(IsWindowResized())
        {
            // TODO: handle auto adjusting either width or height to maintain
            // the target aspect ratio
        }

        // Input Handling ------------------------------------------------------
        currentScene->handleInput(this);

        // Update Cycles -------------------------------------------------------
        currentScene->update(this);
        while(clock.getLag() >= timePerUpdate)
        {
            currentScene->fixedUpdate(this);
            clock.updateTick(timePerUpdate);
        }
        currentScene->lateUpdate(this);

        // Rendering -----------------------------------------------------------
        // All draw functions will write to the render texture...
        BeginTextureMode(target);
            currentScene->draw(this);
            currentScene->drawGui(this);
        EndTextureMode();

        // Then the render texture will get scaled up to the window size
        BeginDrawing();
            Vector2 position = { 0, 0 };
            DrawTexturePro(target.texture, source, dest, position, 0.0f, WHITE);
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

void Game::loadScene(Scene *scene)
{
    delete currentScene;
    currentScene = scene;
}
