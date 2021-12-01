#include "include/engine/Game.h"
#include "include/scenes/MainMenuScene.h"

using namespace Catcher::Survivor;

int main()
{
    Game *game = new Game(new MainMenuScene());
    game->run();

    delete game;

    return 0;
}
