#include "world.h"
#include "entity.h"
#include "unit.h"
#include "counter.h"
#include "plch.h"
#include "stats.h"
#include <sstream>
#include <QDebug>

PlCh::PlCh(int cTeam, int newX, int newY, World *newMap, string pName)
{
    map = newMap;
    x = newX;
    y = newY;
    curHealth = 999;
    maxHealth = 999;
    healthChange = true;
    isNew = true;
    team = cTeam;
    absoluteID = ++curID;
    targetable = true;
    attackable = true;
    size = 150; //radius
    type = 4;

    atkDamage = 200;
    atkSpeed = 1;
    armor = 20;
    atkRange = 999;
    detRange = 999;
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

    plName = pName;
    points = new Stats(pName);
    display = true;
    isCheatMode = false;
    canCheatMode = true;
    cheatCounter = new Counter(3000);

    aPressed= false;
    wPressed= false;
    dPressed = false;
    sPressed= false;


    debug = true;
}

void PlCh::command(string cmdString)
{
    std::stringstream strm;
    strm << cmdString;
    //parse for int x for click / button press
    int type;
    int number; //parse for the rest of the stream
    strm>>type>>number;
    if (type == 1)
    {
        Entity *ent = map->getByID(number);
        if(ent->getTeam() != this->team && ent->getAttackable() && ent->getTargetable())
        {
            target = ent;
        }
    }
    else if (type == 2)
    {
        if(number == 1)
        {
            wPressed= true;
        }
        else if (number == 4)
        {
            aPressed= true;
        }
        else if (number == 3)
        {
            sPressed= true;
        }
        else
        {
            dPressed = true;
        }
        target = NULL;
    }
    else
    {
        if(number == 1)
        {
            wPressed= false;
        }
        else if (number == 4)
        {
            aPressed= false;
        }
        else if (number == 3)
        {
            sPressed= false;
        }
        else
        {
            dPressed = false;
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
        if (wPressed || aPressed|| sPressed|| dPressed)
        {
            //qDebug()<<"W "<<wPressed<<" A "<<aPressed<<" S "<<sPressed<<" D "<<dPressed;
            if(wPressed && !aPressed && !sPressed && !dPressed)
            {
                //qDebug()<<"ONLY W";
                y -= speed;
                currentState = 1;
                positionChange = true;
            }
            if(wPressed && aPressed&& !sPressed && !dPressed)
            {
                //qDebug()<<"W AND A";
                y -= (3 * speed) / 4;
                x -= (3 * speed) / 4;
                currentState = 8;
                positionChange = true;
            }
            if(!wPressed && aPressed&& !sPressed && !dPressed)
            {
                //qDebug()<<"ONLY A";
                x -= speed;
                currentState = 7;
                positionChange = true;
            }
            if(!wPressed && aPressed&& sPressed&& !dPressed)
            {
                //qDebug()<<"A AND S";
                y += (3 * speed) / 4;
                x -= (3 * speed) / 4;
                currentState = 6;
                positionChange = true;
            }
            if(!wPressed && !aPressed && sPressed&& !dPressed)
            {
                //qDebug()<<"ONLY S";
                y = y + speed;
                currentState = 5;
                positionChange = true;
            }
            if(!wPressed && !aPressed && sPressed&& dPressed)
            {
                //qDebug()<<"S AND D";
                y += (3 * speed) / 4;
                x += (3 * speed) / 4;
                currentState = 4;
                positionChange = true;
            }
            if(!wPressed && !aPressed && !sPressed && dPressed)
            {
                //qDebug()<<"ONLY D";
                x += speed;
                currentState = 3;
                positionChange = true;
            }
            if(wPressed && !aPressed && !sPressed && dPressed)
            {
                //qDebug()<<"D AND W";
                y -= (3 * speed) / 4;
                x += (3 * speed) / 4;
                currentState = 2;
                positionChange = true;
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

                        if(count->Check())
                        {
                            qDebug()<<"Attacking";
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
                            positionChange = true;
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

                                if(count->Check())
                                {
                                    qDebug()<<"Attacking";
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
                                    positionChange = true;
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

                            if(count->Check())
                            {
                                qDebug()<<"Attacking";
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
                                positionChange = true;
                            }
                        }
                    }
                }
            }
        }
        if(currentState != state)
        {
            state = currentState;
            stateChange = true;
        }
    }
    else
    {
        if(count->Check())
        {
            Alive = true;
            if(team == 1)
            {
                x = 999;
                y = 999;
            }
            else
            {
                x = 999;
                y = 999;
            }
            count->reset(50/atkSpeed);
        }

    }
}

string PlCh::getStats(){return points->toString();}

bool PlCh::damage(int value)
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

void PlCh::die()
{

    //NEEDS CODING
    Alive = false;
    newDead = true;
    count->reset(1500);
}

bool PlCh::Attack()
{
    return target->damage(atkDamage);
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
    stringstream strm;
    if(Alive)
    {

        if(isNew)
        {
            strm<<" "<<(type * 10 + 1)<<" "<<absoluteID<<" "<<team<<" "<<((curHealth * 100)/maxHealth)<<" "<<state<<" "<<x<<" "<<y<<" "<<plName;
            isNew = false;
            healthChange = false;
            stateChange = false;
            positionChange = false;
        }
        else if(!healthChange && !stateChange && positionChange)
        {
                strm<<" "<<(type * 10 + 2)<<" "<<absoluteID<<" "<<x<<" "<<y;
                positionChange = false;

        }
        else if(!healthChange && stateChange && !positionChange)
        {
            strm<<" "<<(type * 10 + 3)<<" "<<absoluteID<<" "<<state;
            stateChange = false;
        }
        else if(!healthChange && stateChange && positionChange)
        {
            strm<<" "<<(type * 10 + 4)<<" "<<absoluteID<<" "<<state<<" "<<x<<" "<<y;
            stateChange = false;
            positionChange = false;
        }
        else if(healthChange && !stateChange && !positionChange)
        {
            strm<<" "<<(type * 10 + 5)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth);
            healthChange = false;
        }
        else if(healthChange && !stateChange && positionChange)
        {
            strm<<" "<<(type * 10 + 6)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth)<<" "<<x<<" "<<y;
            healthChange = false;
            positionChange = false;
        }
        else if(healthChange && stateChange && !positionChange)
        {
            strm<<" "<<(type * 10 + 7)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth)<<" "<<state;
            healthChange = false;
            stateChange = false;
        }
        else if (healthChange && stateChange && positionChange)
        {
            strm<<" "<<(type * 10 + 8)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth)<<" "<<state<<" "<<x<<" "<<y;
            healthChange = false;
            stateChange = false;
            positionChange = false;
        }
        return strm.str();
    }
    else
    {
        if(newDead)
        {
            strm<<" "<<(type * 10 + 9)<<" "<<absoluteID;
            newDead = false;
            return strm.str();
        }
    }
}
