#include "world.h"
#include "entity.h"
#include "unit.h"
#include "tower.h"
#include <sstream>

//999 is an arbitrary, placeholder value

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
    //count(50 / atkSpeed);
    targetPriority = 0;
    state = 5;
    stateChange = true;

    speed = 0;
    canMove = false;
    positionChange = false;
}

bool Tower::Attack(Entity* ent)
{
    return target->damage(atkDamage);
}

void Tower::onTick()
{
    double distance;
    int currentState = state;
    if(target != NULL)
    {
        distance = sqrt(pow(target->getY()-y, 2) + pow(target->getX() - x, 2));
        if(distance < atkRange)
        {
            //SET STATE HERE
            //if(count.Check())
            {
                if(Attack(target))
                {
                    target = NULL;
                }
            }
        }
        else if (distance > atkRange)
        {
            target = NULL;
            Entity* ent = map->getNAE(x,y,team, distance);
            if(ent != NULL)
            {
                if (distance < atkRange)
                {
                    target = ent;
                    //SET STATE HERE
                    /*
                    if(count.Check())
                    {
                        if(Attack(ent))
                        {
                            target = NULL;
                        }
                    }
                    */
                }
            }
        }
    }
    else
    {
        target = NULL;
        Entity* ent = map->getNAE(x,y,team, distance);
        if(ent != NULL)
        {
            if (distance < atkRange)
            {
                //SET STATE HERE
                /*
                target = ent;
                if(count.Check())
                {
                    if(Attack(ent))
                    {
                        target = NULL;
                    }
                }
                */
            }
        }
    }
}

void Tower::die()
{
    state = 99;
    healthChange = true;
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
