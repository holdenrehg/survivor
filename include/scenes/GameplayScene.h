#pragma once
#include "raylib.h"
#include "include/engine/Game.h"
#include "include/engine/Scene.h"

namespace Catcher::Survivor
{
    class GameplayScene : public Scene
    {
        public:
            GameplayScene();
            void handleInput(Game *game) override;
            void draw(Game *game) override;
        private:
            Texture2D tileSprite;
            Texture2D playerSprite;
            int playerSpeed;
            int playerX;
            int playerY;
    };
}
