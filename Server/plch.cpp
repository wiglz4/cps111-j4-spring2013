#include "plch.h"

PlCh::PlCh(int cTeam, int newX, int newY, World *newMap, string pName)
{

}

void PlCh::command(string cmdString)
{
    //parse for int x for click / button press
    int x;
    int rest; //parse for the rest of the stream
    if (x == 1)
    {
        //do targeting bit
    }
    else if (x == 2)
    {
        //create value comparisons for what goes where
    }
    else
    {
        //create value comparisons for what goes where
    }
}

void PlCh::onTick()
{
    //do ai caluclations based upon state and target and bools
}
bool PlCh::damage(int value)
{
    curHealth = curHealth - value;
}
void PlCh::die()
{
    //change state to reflect death
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
string PlCh::save()
{

}

Entity* PlCh::load()
{

}

string PlCh::displayString()
{

}
