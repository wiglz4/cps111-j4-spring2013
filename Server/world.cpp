#include "world.h"

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
//needs coding
}

bool World::boundsCheck(int locX, int locY, int uSize)
{
//needs coding
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
    stringstream save;
    for(int i = 0; i < allEntities.size(); i++)
    {
        strm << allEntities.at(i)->save();
    }
}

void World::load(string loadString)
{
//Needs coding
}

string World::Display()
{
    stringstream strm;
    for(int i = 0; i < allEntities.size(); i++)
    {
        strm <<  allEntities.at(i)->Display();
    }
    return strm.str();
}


World::World(int numPlayers, int numRed, vector<string> names)
{

}

World::World(string name)
{
    Entity* player = new PlCh(1, 2000, 1500, &this, name);
}
