#include "game.h"
#include "world.h"

//NEEDS BUNCHES OF WORK
Game::Game()
{
    over = false;
}


void Game::onTick()
{
    gmap->onTick();
}

void Game::endGame(int team)
{
//NEEDS CODING
}
