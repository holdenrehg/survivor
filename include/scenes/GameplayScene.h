#pragma once
#include "raylib.h"
#include "include/engine/Game.h"
#include "include/engine/Scene.h"

namespace Catcher::Survivor
{
    typedef enum PlayerAnimation { IDLE, WALK_UP, WALK_DOWN, WALK_LEFT, WALK_RIGHT } PlayerAnimation;

    class PlayerAnimator
    {
        public:
            PlayerAnimator();
            void draw(int x, int y);
            void nextFrame();
            void setIdle();
            void setWalkUp();
            void setWalkDown();
            void setWalkLeft();
            void setWalkRight();
        private:
            Texture2D spriteSheet;
            PlayerAnimation currentAnimation;
            int currentFrame;
            int currentFrameLimit;
            Vector2 currentFrames[3];
            int animationDelay;
            long int lastUpdate;
    };

    class GameplayScene : public Scene
    {
        public:
            GameplayScene();
            void handleInput(Game *game) override;
            void update(Game *game) override;
            void draw(Game *game) override;
        private:
            Texture2D tileSprite;
            int playerSpeed;
            int playerX;
            int playerY;
            PlayerAnimator playerAnimator;
    };
}
