#include "core.h"
//999 is an arbitrary, placeholder value;
int Core::curID = 1;
Core::Core(int cTeam, int newX, int newY, World *newMap)
{
    map = newMap;

    x = newX;
    y = newY;
    curHealth = 999;
    maxHealth = 999;
    team = cTeam;
    absoluteID = ++curID;
    updateHealth = true;

    targetable = false;
    attackable = false;

    size = 999; //radius
    type = 1;
    //int sectorID;
}

void Core::endGame()
{
    return false;
}

bool Core::damage(int value)
{
    health = health - value;
    if(health < 0)
    {
        endGame();
    }
    return false;
}
void Core::onTick()
{

}

string Core::save()
{

}

Entity* Core::load()
{

}

string Core::displayString()
{

}

