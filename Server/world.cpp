#include "world.h"

World::World(vector<User *> *vect, Game *thisGame)
{
    //NEEDS CODING
}

Entity *World::getNAE(int locX, int locY, string origColor)
{
//needs coding
}

bool World::boundsCheck(Entity *ent)
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
    return save.str();
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
        strm <<  allEntities.at(i)->Display() <<" ";
    }
    return strm.str();
}

void World::endGame(int team)
{
    game->endGame(team);
}
