#include "game.h"
#include "world.h"
#include "user.h"

//NEEDS BUNCHES OF WORK
Game::Game(std::vector<User *> *unUsers)
{
    users = unUsers;
    gmap = new World(users);
    sock = new QUdpSocket();
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
