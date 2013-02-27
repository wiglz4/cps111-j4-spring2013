#include "minion.h"
//999 is an arbitrary, placeholder value;
Minion::Minion(string cTeam, int mX, int mY)
{

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
    state = "{DIE}";
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
