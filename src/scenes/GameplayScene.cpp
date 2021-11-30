#include "raylib.h"
#include "include/engine/Game.h"
#include "include/scenes/GameplayScene.h"

using namespace Catcher::Survivor;

void GameplayScene::handleInput(Game *game)
{
    //
}

void GameplayScene::draw(Game *game)
{
    ClearBackground(DARKGREEN);
    DrawText("Welcome to the game", 190, 200, 20, LIGHTGRAY);
}
