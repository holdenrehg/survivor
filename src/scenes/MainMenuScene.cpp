#include "raylib.h"
#include "include/engine/Game.h"
#include "include/scenes/GameplayScene.h"
#include "include/scenes/MainMenuScene.h"

using namespace Catcher::Survivor;

void MainMenuScene::handleInput(Game *game)
{
    if(IsKeyPressed(KEY_SPACE))
    {
        GameplayScene *scene = new GameplayScene();
        game->loadScene(scene);
    }
}

void MainMenuScene::draw(Game *game)
{
    ClearBackground(DARKBLUE);
    DrawText("Press space to play", 10, 10, 8, RAYWHITE);
}
