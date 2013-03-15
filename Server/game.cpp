#include "game.h"
#include "world.h"
#include "user.h"
#include "serverwindow.h"

#include <QDebug>

//NEEDS BUNCHES OF WORK
Game::Game(Observer *o, std::vector<User *> *unUsers)
{
    users = unUsers;
    gmap = new World(users, this);
    sock = new QUdpSocket();
    over = false;
    newOver = false;
    obs = o;
}


std::string Game::onTick()
{
    if(!over && !newOver)
    {
    gmap->onTick();
    return gmap->Display();
    }
    else if(newOver)
    {
        QString packet = "97179 50 P BobJonesIII 1 4 20 3 200\n";
        qDebug()<<"Packet made";
        qDebug() << packet;
        //should pull stats from players and place them in this order:
        //PLAYERINDICATOR PLAYERNAME TEAM TOWERKILLS MINIONKILLS PLAYERDEATHS
        //this should be repeated until there are no more players to process then the time in seconds should be added to the last slot
        //packet += QString("%1").arg(team);
        newOver = false;
        over = true;
        return packet.toStdString();
    }
    else
    {

    }
}

void Game::endGame(int team)
{
    //QString packet = "50 P BobJonesIII 1 4 20 3 200";
    //should pull stats from players and place them in this order:
    //PLAYERINDICATOR PLAYERNAME TEAM TOWERKILLS MINIONKILLS PLAYERDEATHS
    //this should be repeated until there are no more players to process then the time in seconds should be added to the last slot
    //packet += QString("%1").arg(team);
    newOver = true;
}
