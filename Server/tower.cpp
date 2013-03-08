#include "world.h"
#include "entity.h"
#include "unit.h"
#include "counter.h"
#include "tower.h"
#include "towershots.h"
#include <sstream>

//999 is an arbitrary, placeholder value

Tower::Tower(int cTeam, int newX, int newY, World *newMap)
{
    map = newMap;
    x = newX;
    y = newY;
    curHealth = 999;
    maxHealth = 999;
    healthChange = false;
    isNew = true;
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
    newDead = false;
    target = NULL;
    count = new Counter(50 / atkSpeed);
    targetPriority = 0;
    state = 5;
    stateChange = false;

    speed = 0;
    canMove = false;
    positionChange = false;
}

bool Tower::Attack()
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
            if(count->Check())
            {
                if(Attack())
                {
                    target = NULL;
                }
            }
        }
        else
        {
            target = NULL;
            Entity* ent = map->getNAE(x,y,team, distance);
            if (distance < atkRange)
            {
                target = ent;
                //SET STATE HERE

                if(count->Check())
                {
                    if(Attack())
                    {
                        target = NULL;
                    }

                }
            }
        }
    }
    else
    {
        target = NULL;
        Entity* ent = map->getNAE(x,y,team, distance);
        if (distance < atkRange)
        {
            //SET STATE HERE

            target = ent;
            if(count->Check())
            {
                if(Attack())
                {
                    target = NULL;
                }

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
    if(Alive)
    {
    curHealth = (double)curHealth - (double) value * (double) armor / 100;
    if(curHealth < 0)
    {
        die();
        return true;
    }
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
    //bools: isNew, healthChange, stateChange
    stringstream strm;
    if(Alive)
    {
        if(isNew)
        {
            strm<<" "<<(type * 10 + 1)<<" "<<absoluteID<<" "<<team<<" "<<((curHealth * 100) / maxHealth)<<" "<<state<< " "<<x<<" "<<y;
            isNew = false;
        }
        else if(!healthChange && stateChange)
        {
            strm<<" "<<(type * 10 + 2)<<" "<<absoluteID<<" "<<state;
            stateChange = false;
        }
        else if(healthChange && stateChange)
        {
            strm<<" "<<(type * 10 + 4)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth)<<" "<<state;
            stateChange = false;
            healthChange = false;
        }
        else if(healthChange && !stateChange)
        {
            strm<<" "<<(type * 10 + 3)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth);
            healthChange = false;
        }

    }
    else if(newDead)
    {
        strm<<" "<<(type * 10 + 5)<<" "<<absoluteID;
        newDead = false;
    }
    return strm.str();
}
