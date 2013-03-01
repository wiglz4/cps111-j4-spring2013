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
    team = cTeam;
    absoluteID = ++curID;
    updateHealth = true;
    targetable = true;
    attackable = true;
    size = 999; //radius
    type = 2;
    //int sectorID;

    atkDamage = 999;
    atkSpeed = 999;
    armor = 999;
    atkRange = 999;
    detRange = 999;
    canAttack = true;
    Alive = true;
    doneDie = false;
    //AI personal;
    target = NULL;
    count(5);
    targetPriority = 0;
    state = "1";
    updateState = true;
}

bool Tower::Attack()
{
    return target->damage(atkDamage);
}

void Tower::onTick()
{
    //Tower AI goes here
}

void Tower::die()
{
    //Process animation and label deletion here
    //At the end, Alive = false;
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

}

Entity* Tower::load()
{

}

string Tower::displayString()
{

}
