#include "tower.h"
#include <sstream>
//999 is an arbitrary, placeholder value;
Tower::Tower(int cTeam, int newX, int newY, World *newMap)
{
    map = newMap;
    x = newX;
    y = newY;
    curHealth = 999;
    maxHealth = 999;
    healthChange = true;
    team = cTeam;
    absoluteID = ++curID;
    targetable = true;
    attackable = true;
    size = 150; //radius
    type = 1;

    atkDamage = 200;
    atkSpeed = 1;
    armor = 20;
    atkRange = 999;
    detRange = 999;
    canAttack = true;
    Alive = true;
    doneDie = false;
    target = NULL;
    count(5);
    targetPriority = 0;
    state = 5;
    stateChange = true;
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
