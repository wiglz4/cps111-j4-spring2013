#include "world.h"
#include "entity.h"
#include "unit.h"
#include "counter.h"
#include "minion.h"
#include <sstream>
#include <QDebug>
//999 is an arbitrary, placeholder value

Minion::Minion(int cTeam, int newX, int newY, World *newMap)
{
    map = newMap;
    x = newX;
    y = newY;
    curHealth = 500;
    maxHealth = 500;
    healthChange = true;
    isNew = true;
    team = cTeam;
    absoluteID = ++curID;
    targetable = true;
    attackable = true;
    size = 150; //radius
    type = 3;

    atkDamage = 400;
    atkSpeed = 1.2;
    armor = 20;
    atkRange = 35;
    detRange = 600;
    canAttack = true;
    Alive = true;
    newDead = false;
    target = NULL;
    count = new Counter(50/atkSpeed);
    targetPriority = 0;
    state = 5;
    stateChange = true;

    speed = 4;
    canMove = true;
    positionChange = true;
    OOL = false;

    //CHANGE WITH IFS
    if(team == 1)
    {
        cpX = 330;
        cpY = 2545;
    }
    else
    {
        cpX = 3345;
        cpY = 385;
    }

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
    if(Alive)
    {
        if(target != NULL && target->getAttackable())
        {
            distance = sqrt(pow(target->getY()-y, 2) + pow(target->getX() - x, 2));
            if(distance < detRange)
            {
                if(distance < atkRange)
                {

                    if(count->Check())
                    {
                        //STATE Calculations here
                        if(Attack())
                        {
                            target = NULL;
                        }
                    }

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
                if (ent != NULL && ent->getAttackable())
                {
                    if(distance < detRange)
                    {
                        target = ent;
                        if (distance < atkRange)
                        {

                            if(count->Check())
                            {
                                //State Calculations here
                                if(Attack())
                                {
                                    target = NULL;
                                }
                            }

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
            Entity *ent = map->getNAE(x,y, team, distance);
            if (ent != NULL && ent->getAttackable() && ent->getTeam() != this->team)
            {
                if(distance < detRange)
                {
                    target = ent;
                    if (distance < atkRange)
                    {                     
                        if(count->Check())
                        {
                            //SET STATE HERE
                            if(Attack())
                            {
                                target = NULL;
                            }
                        }

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
                            //OOL = false;
                        }
                    }
                } else
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
    if(Alive)
    {
        curHealth = (double)curHealth - (double) value * (double) armor / 100;
        if(curHealth < 0)
        {
            die();
            qDebug() << "died";
            return true;
        }
        healthChange = true;
    }
    return false;
}

void Minion::die()
{
    positionChange = false;
    stateChange = false;
    healthChange = false;
    attackable = false;
    Alive = false;
    newDead = true;
    curHealth = 0;

}

bool Minion::Attack()
{
    return target->damage(atkDamage);
}

string Minion::save()
{
    stringstream save;
    save<<" "<<(type * 10 + 1)<<" "<<absoluteID<<" "<<team<<" "<<((curHealth * 100) / maxHealth)<<" "<<state<< " "<<x<<" "<<y<<" "<<"NOT";
    return save.str();
}

Entity* Minion::load()//Needs redesigning
{
    //NEEDS CODING
    return NULL;
}

string Minion::displayString()
{
    stringstream strm;
    if(Alive)
    {
        if(isNew)
        {
            strm<<" "<<(type * 10 + 1)<<" "<<absoluteID<<" "<<team<<" "<<((curHealth * 100) / maxHealth)<<" "<<state<<" "<<x<<" "<<y<<" "<<"NOT";
            isNew = false;
            //positionChange = false;
            healthChange = false;
            stateChange = false;
        }
        else if (!healthChange && !stateChange && positionChange)
        {
            strm<<" "<<(type *10 + 2)<<" "<<absoluteID<<" "<<x<<" "<<y;
            //positionChange = false;
        }
        else if (!healthChange && stateChange && !positionChange)
        {
            strm<<" "<<(type * 10 + 3)<<" "<<absoluteID<<" "<<state;
            stateChange = false;
        }
        else if (!healthChange && stateChange && positionChange)
        {
            strm<<" "<<(type * 10 + 4)<<" "<<absoluteID<<" "<<state<<" "<<x<<" "<<y;
            stateChange = false;
            //positionChange = false;
        }
        else if (healthChange && !stateChange && !positionChange)
        {
            strm<<" "<<(type * 10 + 5)<<" "<<absoluteID<<" "<<((curHealth * 100)/ maxHealth);
            healthChange = false;
        }
        else if (healthChange && !stateChange && positionChange)
        {
            strm<<" "<<(type * 10 + 6)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth)<<" "<<x<<" "<<y;
            healthChange = false;
            //positionChange = false;
        }
        else if (healthChange && stateChange && !positionChange)
        {
            strm<<" "<<(type * 10 + 7)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth)<<" "<<state;
            healthChange = false;
            stateChange =false;
        }
        else if (healthChange && stateChange && positionChange)
        {
            strm<<" "<<(type * 10 + 8)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth)<<" "<<state<<" "<<x<<" "<<y;
            healthChange = false;
            stateChange = false;
            //positionChange = false;
        }
    } else if(newDead)
    {
        strm<<" "<<(type * 10 + 9)<<" "<<absoluteID;
        newDead = false;
    }

    return strm.str();
}

