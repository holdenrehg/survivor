#include "raylib.h"
#include "include/scenes/MainMenuScene.h"

using namespace Catcher::Survivor;

void MainMenuScene::draw()
{
    ClearBackground(RAYWHITE);
    DrawText("Press space to play", 190, 200, 20, LIGHTGRAY);
}
