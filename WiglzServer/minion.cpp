#include "world.h"
#include "entity.h"
#include "unit.h"
#include "minion.h"

//999 is an arbitrary, placeholder value

Minion::Minion(int cTeam, int newX, int newY, World *newMap)
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
    atkSpeed = 1.2;
    armor = 20;
    atkRange = 999;
    detRange = 999;
    canAttack = true;
    Alive = true;
    doneDie = false;
    target = NULL;
    //count(50/atkSpeed);
    targetPriority = 0;
    state = 5;
    stateChange = true;

    speed = 4;
    canMove = true;
    positionChange = true;

    cpX = 999;
    cpY = 999;
    OOL = false;
    laneX = 999;
    laneY = 999;
}


//Fix this (split it up into methods)
void Minion::onTick()
{
    double distance = 0;
    double theta;
    double delta;
    int tempX;
    int tempY;
    int currentState = state;
    if(target != NULL)
    {
        distance = sqrt(pow(target->getY()-y, 2) + pow(target->getX() - x, 2));
        if(distance < detRange)
        {
            if(distance < atkRange)
            {
                /*
                if(count.Check())
                {
                    //STATE Calculations here
                    if(Attack(target))
                    {
                        target = NULL;
                    }
                }
                */
            }
            else
            {
                theta = asin((y-target->getY())/distance);
                delta = acos((x-target->getX())/distance);
                if(target->getY() > y)
                {
                    tempY = y + abs(speed * sin(theta));
                }
                else
                {
                    tempY = y - abs(speed * sin(theta));
                }
                if(target->getX() > x)
                {
                    tempX = x + abs(speed * cos(theta));
                }
                else
                {
                    tempX = x - abs(speed * cos(theta));
                }
                if(map->boundsCheck(tempX, tempY))
                {
                    //STATE Calculations here
                    x = tempX;
                    y = tempY;
                    //OOL calculations here
                }
            }
        }
        else
        {
            Entity *ent = map->getNAE(x,y,team, distance);
            if (ent != NULL)
            {
                if(distance < detRange)
                {
                    target = ent;
                    if (distance < atkRange)
                    {
                        /*
                        if(count.Check())
                        {
                            //State Calculations here
                            if(Attack(target))
                            {
                                target = NULL;
                            }
                        }
                        */
                    }
                    else
                    {
                        theta = asin((y-target->getY())/distance);
                        delta = acos((x-target->getX())/distance);
                        if(target->getY() > y)
                        {
                            tempY = y + abs(speed * sin(theta));
                        }
                        else
                        {
                            tempY = y - abs(speed * sin(theta));
                        }
                        if(target->getX() > x)
                        {
                            tempX = x + abs(speed * cos(theta));
                        }
                        else
                        {
                            tempX = x - abs(speed * cos(theta));
                        }
                        if(map->boundsCheck(tempX, tempY))
                        {
                            //SET STATE HERE
                            x = tempX;
                            y = tempY;
                            //MESS WITH OOL
                        }
                    }
                }
                else
                {
                    if(OOL)
                    {
                        //SPECIAL OOL LOGIC
                    }
                    else
                    {
                        distance = sqrt(pow(cpY-y, 2) + pow(cpX - x, 2));
                        theta = asin((y-cpY)/distance);
                        delta = acos((x-cpX)/distance);
                        if(cpY > y)
                        {
                            tempY = y + abs(speed * sin(theta));
                        }
                        else
                        {
                            tempY = y - abs(speed * sin(theta));
                        }
                        if(cpX > x)
                        {
                            tempX = x + abs(speed * cos(theta));
                        }
                        else
                        {
                            tempX = x - abs(speed * cos(theta));
                        }
                        if(map->boundsCheck(tempX, tempY))
                        {
                            //SET STATE HERE
                            x = tempX;
                            y = tempY;
                            //MESS WITH OOL
                        }
                    }
                }
            }
        }
    }
    else
    {
        Entity *ent = map->getNAE(x,y,team, distance);
        if (ent != NULL)
        {
            if(distance < detRange)
            {
                target = ent;
                if (distance < atkRange)
                {
                    /*
                    if(count.Check())
                    {
                        //SET STATE HERE
                        if(Attack(target))
                        {
                            target = NULL;
                        }
                    }
                    */
                }
                else
                {
                    theta = asin((y-target->getY())/distance);
                    delta = acos((x-target->getX())/distance);
                    if(target->getY() > y)
                    {
                        tempY = y + abs(speed * sin(theta));
                    }
                    else
                    {
                        tempY = y - abs(speed * sin(theta));
                    }
                    if(target->getX() > x)
                    {
                        tempX = x + abs(speed * cos(theta));
                    }
                    else
                    {
                        tempX = x - abs(speed * cos(theta));
                    }
                    if(map->boundsCheck(tempX, tempY))
                    {
                        //SET STATE HERE
                        x = tempX;
                        y = tempY;
                        //MESS WITH OOL
                    }
                }
            }
            else
            {
                if(OOL)
                {
                    //SPECIAL OOL LOGIC
                }
                else
                {
                    distance = sqrt(pow(cpY-y, 2) + pow(cpX - x, 2));
                    theta = asin((y-cpY)/distance);
                    delta = acos((x-cpX)/distance);
                    if(cpY > y)
                    {
                        tempY = y + abs(speed * sin(theta));
                    }
                    else
                    {
                        tempY = y - abs(speed * sin(theta));
                    }
                    if(cpX > x)
                    {
                        tempX = x + abs(speed * cos(theta));
                    }
                    else
                    {
                        tempX = x - abs(speed * cos(theta));
                    }
                    if(map->boundsCheck(tempX, tempY))
                    {
                        //SET STATE HERE
                        x = tempX;
                        y = tempY;
                        //MESS WITH OOL
                    }
                }
            }
        }
    }
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

bool Minion::Attack(Entity *ent)
{
    return target->damage(atkDamage);
}

string Minion::save()
{
    //NEED CODING
}

Entity* Minion::load()
{
    //NEEDS CODING
}

string Minion::displayString()
{
    //NEEDS CODING
}

