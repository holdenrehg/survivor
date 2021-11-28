#pragma once

namespace Catcher::Survivor
{
    class Game
    {
        public:
            Game();
            void run();
            void stop();

        private:
            bool running;
    };
}
