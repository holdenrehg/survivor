#pragma once
#include "include/engine/Game.h"
#include "include/engine/Scene.h"

namespace Catcher::Survivor
{
    class GameplayScene : public Scene
    {
        void handleInput(Game *game) override;
        void draw(Game *game) override;
    };
}
