#include "world.h"

World::World(vector<User *> *vect, Game *thisGame)
{
    //NEEDS CODING
}

Entity *World::getNAE(Entity *ent, int &distance)
{
    double dist2 = 0;
    distance = 0;
    int entNum = -1;
    if( ent->getTeam() == 1)//red
    {
        for(int i = 0; i < blueEntities.size(); ++i)
        {
            dist2 = sqrt(pow(blueEntities.at(i)->getY()-ent->getY(), 2) + pow(blueEntities.at(i)->getX() - ent->getX(), 2));
            if(dist2 > distance)
            {
                distance = dist2;
                entNum = i;
            }
        }
        if(entNum != -1)
        {
            return blueEntities.at(entNum);
        }
    }
    else//blue
    {
        for(int i = 0; i < redEntities.size(); ++i)
        {
            dist2 = sqrt(pow(redEntities.at(i)->getY()-ent->getY(), 2) + pow(redEntities.at(i)->getX() - ent->getX(), 2));
            if(dist2 > distance)
            {
                distance = dist2;
                entNum = i;
            }
        }
        if(entNum != -1)
        {
            return redEntities.at(entNum);
        }
    }
    return NULL;
}

bool World::boundsCheck(int x, int y)
{
    //needs coding
}

Entity *World::getByID(int entID)
{
    for (int i = 0; i < allEntities.size(); ++i)
    {
        if(allEntities.at(i)->getID() == entID)
        {
            return allEntities.at(i);
        }
    }
    return NULL;
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
