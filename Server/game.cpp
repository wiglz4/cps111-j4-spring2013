#include "game.h"

//NEEDS BUNCHES OF WORK

Game::Game()
{
    over = false;
}


void Game::onTick()
{
    map->onTick();
}
