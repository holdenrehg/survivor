#include "raylib.h"
#include "include/colors.h"
#include "include/engine/Game.h"
#include "include/scenes/GameplayScene.h"

using namespace Catcher::Survivor;

GameplayScene::GameplayScene()
{
    tileSprite = LoadTexture("resources/textures/tiles/tile_0000.png");
    playerSprite = LoadTexture("resources/textures/sprites/character2.png");
    playerSpeed = 1;
    playerX = 10;
    playerY = 10;
}

void GameplayScene::handleInput(Game *game)
{
    if(IsKeyDown(KEY_LEFT)) playerX -= playerSpeed;
    if(IsKeyDown(KEY_RIGHT)) playerX += playerSpeed;
    if(IsKeyDown(KEY_UP)) playerY -= playerSpeed;
    if(IsKeyDown(KEY_DOWN)) playerY += playerSpeed;
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
    DrawTexture(playerSprite, playerX, playerY, WHITE);
}
