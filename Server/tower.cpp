#include "tower.h"
#include <sstream>
//999 is an arbitrary, placeholder value;
Tower::Tower(int cTeam, int newX, int newY, World *newMap)
{
    //NEEDS CODING
}

bool Tower::Attack()
{
    return target->damage(atkDamage);
}

void Tower::onTick()
{
    //NEEDS CODING
}

void Tower::die()
{
    //NEEDS CODING
}

bool Tower::damage(int value)
{
    curHealth = (double)curHealth - (double) value * (double) armor / 100;
    if(curHealth < 0)
    {
        die();
        return true;
    }
    return false;
}

string Tower::save()
{
    //NEEDS CODING
}

Entity* Tower::load()
{
    //NEEDS CODING
}

string Tower::displayString()
{
    //NEEDS CODING
}
