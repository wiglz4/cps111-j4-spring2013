#include "world.h"

//cmdString is a formatted string containing information regarding the number of players, names of the players, player class choices, and who is on which team
World::World(string cmdString)
{

}


void World::plCom(int ID, string com)
{
    for(int i = 0; i < allPlChs.size(); ++i)
    {
        if(ID == allPlChs.at(i)->getID())
        {
            allPlChs.at(i)->command(com);
            break;
        }
    }
}

Entity *World::getNAE(int locX, int locY, string origColor)
{

}

bool World::boundsCheck(int locX, int locY, int uSize)
{

}

void World::onTick()
{
    for(int i = 0; i < allEntities.size(); ++i)
    {
        allEntities.at(i)->onTick();
    }
    for(inti = 0; i < shots.size(); ++i)
    {
        shots.at(i)->onTick();
    }
}

string World::save()
{

}

void World::load(string loadString)
{

}
