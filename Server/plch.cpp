#include "plch.h"

PlCh::PlCh(int cTeam, int newX, int newY, World *newMap, string pName)
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

    speed = 4;
    canMove = true;
    positionChange = true;

    plName = pName;
    points = new Stats(pName);
    display = true;
    isCheatMode = false;
    canCheatMode = true;
    cheatCounter(60);
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
