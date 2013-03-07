#include "game.h"
#include "world.h"

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

}
