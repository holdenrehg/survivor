#pragma once
#include "raylib.h"
#include "include/engine/Clock.h"

namespace Catcher::Survivor
{
    class Scene;  // forward delcaration

    class Game
    {
        public:
            Game(Scene *initialScene);
            ~Game();
            Camera2D camera;
            void run();
            void stop();
            void loadScene(Scene *scene);
        private:
            Clock clock;
            Scene *currentScene;
            bool shouldRun;
            long int timePerUpdate;
            bool isRunning();
    };
}
