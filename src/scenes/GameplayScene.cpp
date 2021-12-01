#include "raylib.h"
#include "include/colors.h"
#include "include/engine/time.h"
#include "include/engine/Game.h"
#include "include/scenes/GameplayScene.h"

using namespace Catcher::Survivor;

PlayerAnimator::PlayerAnimator()
{
    spriteSheet = LoadTexture("resources/textures/character_sheet.png");
    animationDelay = 500;
    lastUpdate = timeSinceEpoch();
    setIdle();
}

void PlayerAnimator::draw(int x, int y)
{
    Vector2 spritePosition = currentFrames[currentFrame];
    Rectangle slice = { spritePosition.x, spritePosition.y, 16, 16 };
    Vector2 position = { (float)x, (float)y };
    DrawTextureRec(spriteSheet, slice, position, WHITE);
}

void PlayerAnimator::nextFrame()
{
    if(timeSinceEpoch() - lastUpdate > animationDelay)
    {
        currentFrame = (currentFrame + 1) % currentFrameLimit;
        lastUpdate = timeSinceEpoch();
    }
}

void PlayerAnimator::setIdle()
{
    if(currentAnimation != IDLE)
    {
        currentFrame = 0;
        currentFrameLimit = 2;
        currentAnimation = IDLE;
    }

    Vector2 frame0 = { 0, 0 };
    currentFrames[0] = { frame0 };

    Vector2 frame1 = { 16, 0 };
    currentFrames[1] = { frame1 };
}

void PlayerAnimator::setWalkUp()
{
    if(currentAnimation != WALK_UP)
    {
        currentFrame = 0;
        currentFrameLimit = 1;
        currentAnimation = WALK_UP;
    }

    Vector2 frame0 = { 0, 32 };
    currentFrames[0] = { frame0 };
}

void PlayerAnimator::setWalkDown()
{
    if(currentAnimation != WALK_DOWN)
    {
        currentFrame = 0;
        currentFrameLimit = 1;
        currentAnimation = WALK_DOWN;
    }

    Vector2 frame0 = { 0, 16 };
    currentFrames[0] = { frame0 };
}

void PlayerAnimator::setWalkLeft()
{
    if(currentAnimation != WALK_LEFT)
    {
        currentFrame = 0;
        currentFrameLimit = 1;
        currentAnimation = WALK_LEFT;
    }

    Vector2 frame0 = { 0, 64 };
    currentFrames[0] = { frame0 };
}

void PlayerAnimator::setWalkRight()
{
    if(currentAnimation != WALK_RIGHT)
    {
        currentFrame = 0;
        currentFrameLimit = 1;
        currentAnimation = WALK_RIGHT;
    }

    Vector2 frame0 = { 0, 48 };
    currentFrames[0] = { frame0 };
}

GameplayScene::GameplayScene()
{

    tileSprite = LoadTexture("resources/textures/tiles/tile_0000.png");
    playerAnimator = PlayerAnimator();
    playerSpeed = 1;
    playerX = 10;
    playerY = 10;
}

void GameplayScene::handleInput(Game *game)
{

    if(IsKeyDown(KEY_LEFT))
    {
        playerAnimator.setWalkLeft();
        playerX -= playerSpeed;
    }
    else if(IsKeyDown(KEY_RIGHT))
    {
        playerAnimator.setWalkRight();
        playerX += playerSpeed;
    }
    else if(IsKeyDown(KEY_UP))
    {
        playerAnimator.setWalkUp();
        playerY -= playerSpeed;
    }
    else if(IsKeyDown(KEY_DOWN))
    {
        playerAnimator.setWalkDown();
        playerY += playerSpeed;
    }
    else
    {
        playerAnimator.setIdle();
    }
}

void GameplayScene::update(Game *game)
{

    playerAnimator.nextFrame();
}

void GameplayScene::draw(Game *game)
{
    ClearBackground(COLOR_PRIMARY);

    // Draw flooring -----------------------------------------------------------
    const int tileSize = 16;  // equal width and height
    const int gridWidth = 32;
    const int gridHeight = 32;

    for(int columnIndex = 0; columnIndex < gridWidth; columnIndex++)
    {
        for(int rowIndex = 0; rowIndex < gridHeight; rowIndex++)
        {
            DrawTexture(tileSprite, columnIndex * tileSize, rowIndex * tileSize, WHITE);
        }
    }

    // Draw player sprite ------------------------------------------------------
    playerAnimator.draw(playerX, playerY);
}
