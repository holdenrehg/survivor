#include "include/engine/Game.h"
#include "include/scenes/MainMenuScene.h"

using namespace std;
using namespace Catcher::Survivor;

int main()
{
    MainMenuScene *scene = new MainMenuScene();
    Game *game = new Game(scene);

    game->run();

    return 0;
}
