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
    curHealth = 2000;
    maxHealth = 2000;
    healthChange = false;
    isNew = true;
    team = cTeam;
    absoluteID = ++curID;
    targetable = true;
    attackable = true;
    size = 150; //radius
    type = 2;
    atkDamage = 800;
    atkSpeed = 1;
    armor = 20;
    atkRange = 500;
    detRange = 500;
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
    if(!Alive)
    {
        return;
    }
    double distance;
    int newState;

    if(target != NULL && target->getAttackable())
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
            newState = World::determineState(x, y, target->getX(), target->getY());
            if(newState != state)
            {
                stateChange = true;
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
                newState = World::determineState(x,y, target);
                if(newState != state)
                {
                    stateChange = true;
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
            state = 5;

            target = ent;
            if(count->Check())
            {
                if(Attack())
                {
                    target = NULL;
                }

            }
            newState = World::determineState(x,y, target);
            if(newState != state)
            {
                stateChange = true;
            }
        }
    }

}

void Tower::die()
{
    //state = 99;
    positionChange = false;
    stateChange = false;
    healthChange = false;
    attackable = false;
    Alive = false;
    newDead = true;
    curHealth = 0;


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
    healthChange = true;
    return false;
}

string Tower::save()
{
    stringstream save;
    save<<" "<<(type * 10 + 1)<<" "<<absoluteID<<" "<<team<<" "<<((curHealth * 100) / maxHealth)<<" "<<state<< " "<<x<<" "<<y<<" "<<"NOT";
    return save.str();
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
            strm<<" "<<(type * 10 + 1)<<" "<<absoluteID<<" "<<team<<" "<<((curHealth * 100) / maxHealth)<<" "<<state<< " "<<x<<" "<<y<<" "<<"NOT";
            isNew = false;
        }
        else if(!healthChange && stateChange)
        {
            strm<<" "<<(type * 10 + 3)<<" "<<absoluteID<<" "<<state;
            stateChange = false;
        }
        else if(healthChange && stateChange)
        {
            strm<<" "<<(type * 10 + 7)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth)<<" "<<state;
            stateChange = false;
            healthChange = false;
        }
        else if(healthChange && !stateChange)
        {
            strm<<" "<<(type * 10 + 5)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth);
            healthChange = false;
        }

    }
    else if(newDead)
    {
        strm<<" "<<(type * 10 + 9)<<" "<<absoluteID;
        newDead = false;
    }
    return strm.str();
}
