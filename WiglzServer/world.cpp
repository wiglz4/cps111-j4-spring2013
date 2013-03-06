#include "game.h"
#include "world.h"
#include "entity.h"
#include "user.h"
#include <sstream>

World::World(vector<User *> *vect)
{
    //NEEDS CODING
}


Entity *World::getNAE(int x, int y, int team, double &distance)
{
    double dist2 = 0;
    distance = 0;
    int entNum = -1;
    if( team == 1)//red
    {
        for(unsigned int i = 0; i < blueEntities.size(); ++i)
        {
            dist2 = sqrt(pow(blueEntities.at(i)->getY()-y, 2) + pow(blueEntities.at(i)->getX() - x, 2));
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
        for(unsigned int i = 0; i < redEntities.size(); ++i)
        {
            dist2 = sqrt(pow(redEntities.at(i)->getY()-y, 2) + pow(redEntities.at(i)->getX() - x, 2));
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
    for (unsigned int i = 0; i < allEntities.size(); ++i)
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

}


string World::save()
{
    stringstream save;

    return save.str();
}


void World::load(string loadString)
{
//Needs coding
}


string World::Display()
{
    stringstream strm;

    return strm.str();
}


void World::endGame(int team)
{
    game->endGame(team);
}
