#pragma once

namespace Catcher::Survivor
{
    class Clock
    {
        public:
            Clock();
            long int getCurrentTime();
            long int getLag();
            void updateTick(long int timePerUpdate);
            void resetTime();
            void tick();
        private:
            long int lag;
            long int previousTime;
    };
}
