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
    underCommand = false;

    a = false;
    w = false;
    d = false;
    s = false;
}

void PlCh::command(string cmdString)
{
    stringstream strm(cmdString);
    //parse for int x for click / button press
    int type;
    int number; //parse for the rest of the stream
    strm>>type>>number;
    if (type == 1)
    {
        Entity *ent = map->getByID(number);
        if(ent->team != this->team && ent->attackable && ent->targetable)
        {
            target = ent;
        }
    }
    else if (type == 2)
    {
        if(number == 1)
        {
            w = true;
        }
        else if (number == 4)
        {
            a = true;
        }
        else if (number == 3)
        {
            s = true;
        }
        else
        {
            d = true;
        }
        target = NULL;
    }
    else
    {
        if(number == 1)
        {
            w = false;
        }
        else if (number == 2)
        {
            a = false;
        }
        else if (number == 3)
        {
            s = false;
        }
        else
        {
            d = false;
        }
    }
}

void PlCh::cheatMode()
{
    //NEEDS CODING
}

void PlCh::onTick()
{
    double distance = 0;
    double theta;
    double delta;
    int tempX;
    int tempY;
    int currentState = state;
    if(Alive)
    {
        //if(underCommand)
        //{
        if (w || a || s || d)
        {
            if(w && a && !s && !d)
            {

            }
            if(w && !a && !s && !d)
            {

            }
            if(!w && a && !s && !d)
            {

            }
            if(!w && a && s && !d)
            {

            }
            if(!w && !a && s && !d)
            {

            }
            if(!w && !a && s && d)
            {

            }
            if(!w && !a && !s && d)
            {

            }
            if(w && !a && !s && d)
            {

            }
        }
        //}
        else
        {
            if(target != NULL)
            {
                distance = sqrt(pow(target->getY()-y, 2) + pow(target->getX() - x, 2));
                if(distance < detRange)
                {
                    if(distance < atkRange)
                    {
                        if(count.Check())
                        {
                            //STATE Calculations here
                            if(Attack(target))
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
                        }
                    }
                }
                else
                {
                    Entity *ent = map->getNAE(&this, distance);
                    if (ent != NULL)
                    {
                        if(distance < detRange)
                        {
                            target = ent;
                            if (distance < atkRange)
                            {
                                if(count.Check())
                                {
                                    //State Calculations here
                                    if(Attack(target))
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
                            /*if(OOL)
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
                            }*/
                        }
                    }
                }
            }
            else
            {
                Entity *ent = map->getNAE(&this, distance);
                if (ent != NULL)
                {
                    if(distance < detRange)
                    {
                        target = ent;
                        if (distance < atkRange)
                        {
                            if(count.Check())
                            {
                                //SET STATE HERE
                                if(Attack(target))
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
                            }
                        }
                    }
                    else
                    {
                        /*if(OOL)
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
                        }*/
                    }
                }
            }
        }
    }
    else
    {
        if(count.Check())
        {
            Alive = true;
            count.reset(50/atkSpeed);
        }
    }
}

bool PlCh::damage(int value)
{
    curHealth = curHealth - value;
}

void PlCh::die()
{
    //NEEDS CODING
    Alive = false;
    count.reset(1500);
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
