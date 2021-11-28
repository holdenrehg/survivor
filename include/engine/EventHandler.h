#pragma once

#include "include/engine/Event.h"

namespace Catcher::Survivor
{
    class EventHandler
    {
        public:
            Event wait();
            void dispatch();
    };
}
