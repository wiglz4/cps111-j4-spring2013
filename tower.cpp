#include "tower.h"
#include <sstream>
//999 is an arbitrary, placeholder value;
int Tower::redId = 1;
int Tower::blueId = 1;
Tower::Tower(string cTeam, int tX, int tY)
{

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
