#include "raylib.h"
#include "include/colors.h"
#include "include/engine/time.h"
#include "include/engine/Game.h"
#include "include/scenes/GameplayScene.h"

using namespace Catcher::Survivor;

PlayerAnimator::PlayerAnimator()
{
    spriteSheet = LoadTexture("resources/textures/character_sheet.png");
    lastUpdate = timeSinceEpoch();
    setIdle();
}

void PlayerAnimator::draw(int x, int y)
{
    // Draw the shadow underneath the player sprite
    Color shadowColor = {0, 0, 0, 70};
    DrawCircle(x, y - 1, 4, shadowColor);

    // Draw the player sprite
    Vector2 spritePosition = currentFrames[currentFrame];
    Rectangle slice = { spritePosition.x, spritePosition.y, 16, 16 };
    Vector2 position = { (float)x - 8, (float)y - 16 }; // shifted focus point to the bottom middle of the sprite
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
        animationDelay = 500;
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
        currentFrameLimit = 3;
        currentAnimation = WALK_UP;
        animationDelay = 100;
    }

    Vector2 frame0 = { 0, 32 };
    currentFrames[0] = { frame0 };
    Vector2 frame1 = { 16, 32 };
    currentFrames[1] = { frame1 };
    Vector2 frame2 = { 32, 32 };
    currentFrames[2] = { frame2 };
}

void PlayerAnimator::setWalkDown()
{
    if(currentAnimation != WALK_DOWN)
    {
        currentFrame = 0;
        currentFrameLimit = 3;
        currentAnimation = WALK_DOWN;
        animationDelay = 100;
    }

    Vector2 frame0 = { 0, 16 };
    currentFrames[0] = { frame0 };
    Vector2 frame1 = { 16, 16 };
    currentFrames[1] = { frame1 };
    Vector2 frame2 = { 32, 16 };
    currentFrames[2] = { frame2 };
}

void PlayerAnimator::setWalkLeft()
{
    if(currentAnimation != WALK_LEFT)
    {
        currentFrame = 0;
        currentFrameLimit = 2;
        currentAnimation = WALK_LEFT;
        animationDelay = 200;
    }

    Vector2 frame0 = { 0, 64 };
    currentFrames[0] = { frame0 };
    Vector2 frame1 = { 16, 64 };
    currentFrames[1] = { frame1 };
}

void PlayerAnimator::setWalkRight()
{
    if(currentAnimation != WALK_RIGHT)
    {
        currentFrame = 0;
        currentFrameLimit = 2;
        currentAnimation = WALK_RIGHT;
        animationDelay = 200;
    }

    Vector2 frame0 = { 0, 48 };
    currentFrames[0] = { frame0 };
    Vector2 frame1 = { 16, 48 };
    currentFrames[1] = { frame1 };
}

GameplayScene::GameplayScene()
{

    tileSprite = LoadTexture("resources/textures/tiles/tile_0000.png");
    playerAnimator = PlayerAnimator();
    playerSpeed = 1;
    playerX = 480/3;
    playerY = 320/3;
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

    // TODO: need to map between target resolution and the full world size.
    //       Use actual screen size and target size instead of hardcoding here.
    const int localTargetX = playerX - (480/3);
    const int localTargetY = playerY - (320/3);
    game->camera.target.x = (float)localTargetX * 4.0f;
    game->camera.target.y = (float)localTargetY * 4.0f;
}

void GameplayScene::draw(Game *game)
{
    // Draw flooring -----------------------------------------------------------
    const int tileSize = 16;  // equal width and height
    const int gridWidth = 64;
    const int gridHeight = 64;

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
