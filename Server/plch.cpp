#include "plch.h"

PlCh::PlCh(int cTeam, int newX, int newY, World *newMap, string pName)
{
//NEEDS CODING
}

void PlCh::command(string cmdString)
{
    //parse for int x for click / button press
    int x;
    int rest; //parse for the rest of the stream
    if (x == 1)
    {
        //NEEDS CODING - TARGET
    }
    else if (x == 2)
    {
        //NEEDS CODING - BUTTON PRESSED
    }
    else
    {
        //NEEDS CODING - BUTTON RELEASED
    }
}

void PlCh::cheatMode()
{
    //NEEDS CODING
}

void PlCh::onTick()
{
    //NEEDS CODING
}

bool PlCh::damage(int value)
{
    curHealth = curHealth - value;
}

void PlCh::die()
{
    //NEEDS CODING
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

string PlCh::save()
{
    //NEEDS CODING
}

Entity* PlCh::load()
{
    //NEEDS CODING
}

string PlCh::displayString()
{
    //NEEDS CODING
}
