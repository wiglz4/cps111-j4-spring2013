#include "plch.h"

PlCh::PlCh(string cTeam, int pX, int pY, string pName)
{

}

void PlCh::onTick()
{
    //PlCh AI goes here
}
bool PlCh::damage(int value)
{
    curHealth = curHealth - value;
}
void PlCh::die()
{
    //Process animation and label deletion here
}
bool PlCh::Attack()
{
    return target->damage(atkDamage);
}
void PlCh::Move(int newX, int newY)
{
    x = newX;
    y = newY;
}
//void levelUp(){}
