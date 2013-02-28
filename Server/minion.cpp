#include "minion.h"
//999 is an arbitrary, placeholder value;
Minion::Minion(int cTeam, int newX, int newY, World *newMap)
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
    type = 3;
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

    speed = 999;
    canMove = true;
    updatePosition = true;

    //OUT OF LANE
    OOL = false;
    cpX = 999;
    cpY = 999;

}

void Minion::onTick()
{
    //minion AI goes here
}
bool Minion::damage(int value)
{
    curHealth = (double)curHealth - (double) value * (double) armor / 100;
    if(curHealth < 0)
    {
        die();
        return true;
    }
    return false;
}
void Minion::die()
{
    //Process animation and label deletion here
    canAttack = false;
    targetable = false;
    attackable = false;
    canMove = false;
    animState = "{DIE}";
}
bool Minion::Attack()
{
    return target->damage(atkDamage);
}
void Minion::Move(int newX, int newY)
{
    x = newX;
    y = newY;
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

