#pragma once
#include "include/engine/Clock.h"

namespace Catcher::Survivor
{
    class Game
    {
        public:
            Game();
            void run();
            void stop();
        private:
            Clock clock;
            bool running;
            double timePerUpdate;
            void fixedUpdate();
            void lateUpdate();
            void update();
            void draw();
            void drawGui();
    };
}
