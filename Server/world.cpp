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
#include "world.h"
#include "counter.h"
#include <sstream>

#include <QDebug>

World::World()
{

}

World::World(vector<User *> *vect, Game* gam)
{
    //NEEDS CODING
    game = gam;
    tick = 0;

    Core *aCore = new Core(1, 3230, 165,this);
    allEntities.push_back(aCore);
    redEntities.push_back(aCore);

    aCore = new Core(2, 220, 2395,this);
    allEntities.push_back(aCore);
    blueEntities.push_back(aCore);

    Tower *aTower = new Tower(1, 1840, 895,this);
    allEntities.push_back(aTower);
    redEntities.push_back(aTower);
    aTower = new Tower(1, 2630, 805, this);
    allEntities.push_back(aTower);
    redEntities.push_back(aTower);
    aTower = new Tower(1,2820, 165, this);
    allEntities.push_back(aTower);
    redEntities.push_back(aTower);
    aTower = new Tower(1, 3230, 475, this);
    allEntities.push_back(aTower);
    redEntities.push_back(aTower);


    aTower = new Tower(2, 800, 1675, this);
    allEntities.push_back(aTower);
    blueEntities.push_back(aTower);
    aTower = new Tower(2, 1600, 1575, this);
    allEntities.push_back(aTower);
    blueEntities.push_back(aTower);
    aTower = new Tower(2,220,2020,this);
    allEntities.push_back(aTower);
    blueEntities.push_back(aTower);
    aTower = new Tower(2,480,2395,this);
    allEntities.push_back(aTower);
    blueEntities.push_back(aTower);

    int blueMod= 1;
    int redMod=1;
    PlCh* aPlCh;
    for(int i = 0; i < vect->size();++i)
    {
        if(vect->at(i)->getTeam() == 1)
        {
            aPlCh = new PlCh(1, 3230 ,165 + redMod * 100, this, vect->at(i)->getName());
            vect->at(i)->setCharacter(aPlCh);
            allEntities.push_back(aPlCh);
            redEntities.push_back(aPlCh);
        }
        else
        {
            aPlCh = new PlCh(2,250,2500 + blueMod * 100, this, vect->at(i)->getName());
            vect->at(i)->setCharacter(aPlCh);
            allEntities.push_back(aPlCh);
            blueEntities.push_back(aPlCh);
        }
    }
}


Entity *World::getNAE(int x, int y, int team, double &distance)
{
    double dist2 = 0;
    distance = 50000;
    int entNum = -1;
    if(team == 1)//red
    {
        for(unsigned int i = 0; i < blueEntities.size(); ++i)
        {
            dist2 = sqrt(pow(blueEntities.at(i)->getY()-y, 2) + pow(blueEntities.at(i)->getX() - x, 2));
            if(dist2 < distance)
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
    if (team == 2)//blue
    {
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

int World::determineState(Entity *source, Entity *target)
{
    int sourcex = source->getX();
    int sourcey = source->getY();
    int targetx = target->getX();
    int targety = target->getY();
    double a;
    double b;
    double c;
    double theta;
    bool isUnder;
    int state;
    if(targety < sourcey)
    {
        isUnder = true;
    }
    else
    {
        isUnder = false;
    }
    a = sourcex - targetx;
    b = sourcey - targety;
    c = sqrt(pow(a,2)+pow(b,2));
    theta = acos(a/c);
    if(isUnder)
    {
        theta += 180;
    }
    if(112.5 >= theta && theta >= 67.5)
    {
        state = 8;
    }
    if(67.5 >= theta && theta >= 22.5)
    {
        state = 7;
    }
    if(22.5 >=theta || theta >=337.5)
    {
        state = 6;
    }
    if(337.5 >= theta && theta >= 292.5)
    {
        state = 5;
    }
    if(292.5 >= theta && theta >= 247.5)
    {
        state = 4;
    }
    if(247.5 >= theta && theta >= 202.5)
    {
        state = 3;
    }
    if(202.5 >= theta && theta >= 157.5)
    {
        state = 2;
    }
    if(157.5 >= theta && theta >= 112.5)
    {
        state = 1;
    }
    return state;
}

int World::determineState(Entity *source, int cpX, int cpY)
{
    int sourcex = source->getX();
    int sourcey = source->getY();
    int targetx = cpX;
    int targety = cpY;
    double a;
    double b;
    double c;
    double theta;
    bool isUnder;
    int state;
    if(targety < sourcey)
    {
        isUnder = true;
    }
    else
    {
        isUnder = false;
    }
    a = sourcex - targetx;
    b = sourcey - targety;
    c = sqrt(pow(a,2)+pow(b,2));
    theta = acos(a/c);
    if(isUnder)
    {
        theta += 180;
    }
    if(112.5 >= theta && theta >= 67.5)
    {
        state = 8;
    }
    if(67.5 >= theta && theta >= 22.5)
    {
        state = 7;
    }
    if(22.5 >=theta || theta >=337.5)
    {
        state = 6;
    }
    if(337.5 >= theta && theta >= 292.5)
    {
        state = 5;
    }
    if(292.5 >= theta && theta >= 247.5)
    {
        state = 4;
    }
    if(247.5 >= theta && theta >= 202.5)
    {
        state = 3;
    }
    if(202.5 >= theta && theta >= 157.5)
    {
        state = 2;
    }
    if(157.5 >= theta && theta >= 112.5)
    {
        state = 1;
    }
    return state;
}

int World::determineState(int sourcex, int sourcey, Entity *target)
{
    int targetx = target->getX();
    int targety = target->getY();
    double a;
    double b;
    double c;
    double theta;
    bool isUnder;
    int state;
    if(targety < sourcey)
    {
        isUnder = true;
    }
    else
    {
        isUnder = false;
    }
    a = sourcex - targetx;
    b = sourcey - targety;
    c = sqrt(pow(a,2)+pow(b,2));
    theta = acos(a/c);
    if(isUnder)
    {
        theta += 180;
    }
    if(112.5 >= theta && theta >= 67.5)
    {
        state = 8;
    }
    if(67.5 >= theta && theta >= 22.5)
    {
        state = 7;
    }
    if(22.5 >=theta || theta >=337.5)
    {
        state = 6;
    }
    if(337.5 >= theta && theta >= 292.5)
    {
        state = 5;
    }
    if(292.5 >= theta && theta >= 247.5)
    {
        state = 4;
    }
    if(247.5 >= theta && theta >= 202.5)
    {
        state = 3;
    }
    if(202.5 >= theta && theta >= 157.5)
    {
        state = 2;
    }
    if(157.5 >= theta && theta >= 112.5)
    {
        state = 1;
    }
    return state;
}

int World::determineState(int sourcex, int sourcey, int targetx, int targety)
{
    double a;
    double b;
    double c;
    double theta;
    bool isUnder;
    int state;
    if(targety < sourcey)
    {
        isUnder = true;
    }
    else
    {
        isUnder = false;
    }
    a = sourcex - targetx;
    b = sourcey - targety;
    c = sqrt(pow(a,2)+pow(b,2));
    theta = acos(a/c);
    if(isUnder)
    {
        theta += 180;
    }
    if(112.5 >= theta && theta >= 67.5)
    {
        state = 8;
    }
    if(67.5 >= theta && theta >= 22.5)
    {
        state = 7;
    }
    if(22.5 >=theta || theta >=337.5)
    {
        state = 6;
    }
    if(337.5 >= theta && theta >= 292.5)
    {
        state = 5;
    }
    if(292.5 >= theta && theta >= 247.5)
    {
        state = 4;
    }
    if(247.5 >= theta && theta >= 202.5)
    {
        state = 3;
    }
    if(202.5 >= theta && theta >= 157.5)
    {
        state = 2;
    }
    if(157.5 >= theta && theta >= 112.5)
    {
        state = 1;
    }
    return state;
}

bool World::boundsCheck(int x, int y)
{
    if(x < 0 || x > 4000 || y < 0 || y > 3028)
        return false;
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
    for(int i = 0; i < allEntities.size(); ++i)
    {
        allEntities.at(i)->onTick();
    }

    for(int i = 0; i < shots.size(); ++i)
    {
        shots.at(i)->onTick();
    }

    if (tick == 1000)
    {
        for(int i = 0; i < 1; ++i)
        {
            createRedMinion();
            createBlueMinion();
        }
        setTick(0);

    }
    incTick();
}


void World::save()
{
    ofstream saveFile;
    stringstream save;
    for (int i = 0; i < allEntities.size(); i++){
        save << allEntities.at(i)->save();
    }
    saveFile.open ("test.txt");
    saveFile << save.str();
    saveFile.close();
    qDebug() << "file made.";
}


World* World::load(vector<User *> *vect, Game *gam)
{
    /*
    ifstream indata;
    int num;
    char test[5000];
    stringstream load;
    load << "97179";

    indata.open("test.txt");
    if (!indata){
    }
    while (!indata.eof()){
        load << indata.getline(test, 5000);
    }
    qDebug() << "LOADED";
    load<<"\n";
    qDebug() << load;
    return load.str();
    */
}

void World::createRedMinion()
{
    aMinion = new Minion(1, 3345, 385,this);
    allEntities.push_back(aMinion);
    redEntities.push_back(aMinion);
}

void World::createBlueMinion()
{
    aMinion = new Minion(2, 330, 2545,this);
    allEntities.push_back(aMinion);
    blueEntities.push_back(aMinion);
}


string World::Display()
{
    stringstream strm;
    strm<<"97179";
    for(int i = 0; i < allEntities.size(); ++i)
    {
        if(allEntities.at(i) != NULL)
        {
            strm << allEntities.at(i)->displayString();
        }
    }
    for(int i = 0; i < shots.size(); ++i)
    {
        strm << shots.at(i)->DispShot();
    }

    for(int i = 0; i <allMinions.size(); ++i)
    {
        if(!allMinions.at(i)->getAlive())
        {
            delete allMinions.at(i);
            allMinions.erase(allMinions.begin() + i);
        }
    }

    strm<<"\n";
    return strm.str();
}


void World::endGame(int team)
{
    game->endGame(team);
}
