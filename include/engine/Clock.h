#pragma once

namespace Catcher::Survivor
{
    class Clock
    {
        public:
            Clock();
            double getCurrentTime();
            double getLag();
            void updateTick(double timePerUpdate);
            void resetTime();
            void tick();
        private:
            double lag;
            double previousTime;
    };
}
