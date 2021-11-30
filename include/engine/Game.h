#pragma once
#include "include/engine/Clock.h"

namespace Catcher::Survivor
{
    class Scene;  // forward delcaration

    class Game
    {
        public:
            Game(Scene *initialScene);
            void run();
            void stop();
            void loadScene(Scene *scene);
        private:
            Clock clock;
            Scene *currentScene;
            bool shouldRun;
            double timePerUpdate;
            bool isRunning();
    };
}
