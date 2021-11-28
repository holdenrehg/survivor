#include <iostream>
#include "include/engine/Game.h"

using namespace std;
using namespace Catcher::Survivor;

Game::Game()
{
    running = false;
}

void Game::run()
{
    running = true;

    while(running)
    {
        //
    }
}

void Game::stop()
{
    running = false;
}
