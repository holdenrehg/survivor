#pragma once
#include "include/engine/Game.h"

namespace Catcher::Survivor
{
    class Scene
    {
        public:
            virtual void handleInput(Game *game) { };
            virtual void fixedUpdate(Game *game) { };
            virtual void lateUpdate(Game *game) { };
            virtual void update(Game *game) { };
            virtual void draw(Game *game) { };
            virtual void drawGui(Game *game) { };
    };
}
