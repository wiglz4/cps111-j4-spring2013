#include "game.h"
#include "world.h"
#include "entity.h"
#include "core.h"
#include "unit.h"
#include "minion.h"
#include "plch.h"
#include "tower.h"
#include "user.h"
#include "towershots.h"
#include <sstream>

#include <QDebug>

World::World(vector<User *> *vect)
{
    //NEEDS CODING

    int numRed = 0;
    for(int i = 0; i < vect->size(); ++i)
    {
        if(vect->at(i)->getTeam() ==1)
        {
            ++numRed;
        }
    }

    Core *aCore = new Core(1, 100, 100,this);
    allEntities.push_back(aCore);
    redEntities.push_back(aCore);
    qDebug()<<"RedCore";

    aCore = new Core(2, 200, 100,this);
    allEntities.push_back(aCore);
    blueEntities.push_back(aCore);
    qDebug()<<"BlueCore";

    Tower *aTower = new Tower(1, 100,300,this);
    allEntities.push_back(aTower);
    redEntities.push_back(aTower);
    aTower = new Tower(1, 100, 500, this);
    allEntities.push_back(aTower);
    redEntities.push_back(aTower);
    aTower = new Tower(1,100, 700, this);
    allEntities.push_back(aTower);
    redEntities.push_back(aTower);
    aTower = new Tower(1, 100, 900, this);
    allEntities.push_back(aTower);
    redEntities.push_back(aTower);
    qDebug()<<"RedTowers";
    qDebug()<<redEntities.size();

    aTower = new Tower(2, 200, 300, this);
    allEntities.push_back(aTower);
    blueEntities.push_back(aTower);
    aTower = new Tower(2, 200, 500, this);
    allEntities.push_back(aTower);
    blueEntities.push_back(aTower);
    aTower = new Tower(2,200,700,this);
    allEntities.push_back(aTower);
    blueEntities.push_back(aTower);
    aTower = new Tower(2,200,900,this);
    allEntities.push_back(aTower);
    blueEntities.push_back(aTower);
    qDebug()<<"BlueTowers";
    qDebug()<<blueEntities.size();

    Minion *aMinion = new Minion(1, 100, 1000, this);
    allEntities.push_back(aMinion);
    allMinions.push_back(aMinion);
    redEntities.push_back(aMinion);
    aMinion = new Minion(1, 100, 1100, this);
    allEntities.push_back(aMinion);
    allMinions.push_back(aMinion);
    redEntities.push_back(aMinion);
    aMinion = new Minion(1, 100, 1200, this);
    allEntities.push_back(aMinion);
    allMinions.push_back(aMinion);
    redEntities.push_back(aMinion);
    aMinion = new Minion(1, 100, 1300, this);
    allEntities.push_back(aMinion);
    allMinions.push_back(aMinion);
    redEntities.push_back(aMinion);

    aMinion = new Minion(2, 200, 1000, this);
    allEntities.push_back(aMinion);
    allMinions.push_back(aMinion);
    blueEntities.push_back(aMinion);
    aMinion = new Minion(2, 200, 1100, this);
    allEntities.push_back(aMinion);
    allMinions.push_back(aMinion);
    blueEntities.push_back(aMinion);
    aMinion = new Minion(2, 200, 1200, this);
    allEntities.push_back(aMinion);
    allMinions.push_back(aMinion);
    blueEntities.push_back(aMinion);
    aMinion = new Minion(2, 200, 1300, this);
    allEntities.push_back(aMinion);
    allMinions.push_back(aMinion);
    blueEntities.push_back(aMinion);

    int blueMod= 1;
    int redMod=1;
    PlCh* aPlCh;
    for(int i = 0; i < vect->size();++i)
    {
        if(vect->at(i)->getTeam() == 1)
        {
            aPlCh = new PlCh(1,100,1300 + redMod * 100, this, vect->at(i)->getName());
            allEntities.push_back(aPlCh);
            redEntities.push_back(aPlCh);
        }
        else
        {
            aPlCh = new PlCh(1,200,1300 + blueMod * 100, this, vect->at(i)->getName());
            allEntities.push_back(aPlCh);
            blueEntities.push_back(aPlCh);
        }
    }
    //qDebug()<<"Map created";
}


Entity *World::getNAE(int x, int y, int team, double &distance)
{
    double dist2 = 0;
    distance = 400000;
    int entNum = -1;
    if( team == 1)//red
    {
        //qDebug()<<"red";
        //qDebug()<<0 + blueEntities.size();
        for(unsigned int i = 0; i < blueEntities.size(); ++i)
        {
            dist2 = sqrt(pow(blueEntities.at(i)->getY()-y, 2) + pow(blueEntities.at(i)->getX() - x, 2));
            //qDebug()<<dist2;
            if(dist2 < distance)
            {
                qDebug()<<111;
                //distance = dist2;
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
        //qDebug()<<"blue";
        for(unsigned int i = 0; i < redEntities.size(); ++i)
        {
            dist2 = sqrt(pow(redEntities.at(i)->getY()-y, 2) + pow(redEntities.at(i)->getX() - x, 2));
            if(dist2 < distance)
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
    return true;
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
    //qDebug()<<"Map tick started";

    for(int i = 0; i < allEntities.size(); ++i)
    {
        allEntities.at(i)->onTick();
    }

    //qDebug()<<"Entities ticked";

    for(int i = 0; i < shots.size(); ++i)
    {
        shots.at(i)->onTick();
    }

    //qDebug()<<"Shots ticked";
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
    for(int i = 0; i < allEntities.size(); ++i)
    {
        strm<<allEntities.at(i)->displayString();
    }
    for(int i = 0; i < shots.size(); ++i)
    {
        strm<<shots.at(i)->DispShot();
    }
    for(int i = 0; i <allMinions.size(); ++i)
    {
        if(!allMinions.at(i)->getAlive())
        {
            delete allMinions.at(i);
            allMinions.erase(allMinions.begin() + i);
        }
    }
    //qDebug()<<strm.str().c_str();
    return strm.str();
}


void World::endGame(int team)
{
    game->endGame(team);
}
