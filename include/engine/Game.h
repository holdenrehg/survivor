#pragma once
#include "include/engine/Clock.h"
#include "include/engine/Scene.h"

namespace Catcher::Survivor
{
    class Game
    {
        public:
            Game(Scene *initialScene);
            void run();
            void stop();
        private:
            Clock clock;
            Scene *currentScene;
            bool shouldRun;
            double timePerUpdate;
            bool isRunning();
    };
}
