#include "game.h"
#include "world.h"
#include "user.h"
#include "serverwindow.h"

#include <QDebug>

Game::Game(Observer *o, std::vector<User *> *unUsers)
{
    users = unUsers;
    gmap = new World(users, this);
    //sock = new QUdpSocket();
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
        QString packet = "97179 50 "; //P BobJonesIII 1 2 20 2 3 P DrStephenJones 2 4 35 3 2 2000050\n";
        for(int i = 0; i < users->size(); i++){
            User *u = users->at(i);
            packet = packet + "P " + u->score() + " ";
        }
        packet = packet + QString::number(obs->getTime()) + "\n";

        qDebug() << packet;
        //should pull stats from players and place them in this order:
        //PLAYERINDICATOR PLAYERNAME TEAM TOWERKILLS MINIONKILLS PLAYERKILLS PLAYERDEATHS
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

Game* Game::Load(Observer *o, std::vector<User *> *unUsers)
{
    Game* gam = new Game();
    gam->users = unUsers;
    gam->obs = o;
    gam->gmap = World::load(unUsers,gam);
    return gam;
}


Game::Game()
{
    over = false;
    newOver = false;
}
