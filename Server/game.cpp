#include "game.h"
#include "world.h"
#include "user.h"

#include <QDebug>

//NEEDS BUNCHES OF WORK
Game::Game(std::vector<User *> *unUsers)
{
    users = unUsers;
    gmap = new World(users);
    sock = new QUdpSocket();
    over = false;
}


std::string Game::onTick()
{
    //qDebug()<<"Game ticked";
    gmap->onTick();
    //qDebug()<<"Map ticked";
    return gmap->Display();
}

void Game::endGame(int team)
{
//NEEDS CODING
}
