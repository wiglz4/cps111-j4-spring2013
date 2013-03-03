#include "minion.h"
//999 is an arbitrary, placeholder value;
Minion::Minion(int cTeam, int newX, int newY, World *newMap)
{
//NEEDS CODING
}

void Minion::onTick()
{
    //NEEDS CODING
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
//NEEDS CODING
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
    //NEED CODING
}

Entity* Tower::load()
{
//NEEDS CODING
}

string Tower::displayString()
{
//NEEDS CODING
}

