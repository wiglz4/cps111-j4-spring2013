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
    curHealth = 999;//incomplete
    maxHealth = 999;//incomplete
    healthChange = true;
    isNew = true;
    team = cTeam;
    absoluteID = ++curID;
    targetable = true;
    attackable = true;
    size = 150; //radius
    type = 4;

    atkDamage = 2;//incomplete
    atkSpeed = 1;
    armor = 20;
    atkRange = 999;//incomplete
    detRange = 999;//incomplete
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

//Moves player based on keypress, returns new state
int PlCh::moveManual(){
    int currentState = 0;
    //Move (Joel's Magic Mathy Stuff)
    if(wPressed && !aPressed && !sPressed && !dPressed)
    {
        y -= speed;
        currentState = 1;
        positionChange = true;
    }
    if(wPressed && aPressed&& !sPressed && !dPressed)
    {
        y -= (3 * speed) / 4;
        x -= (3 * speed) / 4;
        currentState = 8;
        positionChange = true;
    }
    if(!wPressed && aPressed&& !sPressed && !dPressed)
    {
        x -= speed;
        currentState = 7;
        positionChange = true;
    }
    if(!wPressed && aPressed&& sPressed&& !dPressed)
    {
        y += (3 * speed) / 4;
        x -= (3 * speed) / 4;
        currentState = 6;
        positionChange = true;
    }
    if(!wPressed && !aPressed && sPressed&& !dPressed)
    {
        y = y + speed;
        currentState = 5;
        positionChange = true;
    }
    if(!wPressed && !aPressed && sPressed&& dPressed)
    {
        y += (3 * speed) / 4;
        x += (3 * speed) / 4;
        currentState = 4;
        positionChange = true;
    }
    if(!wPressed && !aPressed && !sPressed && dPressed)
    {
        x += speed;
        currentState = 3;
        positionChange = true;
    }
    if(wPressed && !aPressed && !sPressed && dPressed)
    {
        y -= (3 * speed) / 4;
        x += (3 * speed) / 4;
        currentState = 2;
        positionChange = true;
    }
    return currentState;
}

void PlCh::onTick()
{
    double distance = 0;
    double theta;
    double delta;
    int tempX;
    int tempY;
    int currentState = state;

    if(Alive) //if player is alive
    {
        if (wPressed || aPressed|| sPressed|| dPressed) //and if a key is pressed
        {
           currentState = moveManual(); //move him
        }
        else
        {
            if(target != NULL) //if player is alive and not moving and the target is not null
            {
                //calculate distance to target
                distance = sqrt(pow(target->getY()-y, 2) + pow(target->getX() - x, 2));
                if(distance < detRange) //if target is within detection range
                {
                    if(distance < atkRange) //if target is also within attack range
                    {

                        if(count->Check()) //Who knows
                        {

                            if(target->getAttackable()) //check if can be attacked
                            {
                                Attack(); //attack
                                qDebug()<<"Attacking"; //see if attacked: REM

                            } else { //if you can't attack it, set it to null
                                target = NULL;
                            }
                        }

                    }
                    else //if target is not in detect range but not in attack range, move within attack range
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
                else //if target is not within attack or detect range
                {
                    Entity *ent = map->getNAE(x,y,team, distance); //What on earth does this do?
                    if (ent != NULL) // if entity is not null
                    {
                        if(distance < detRange) //and if entity is within detection range
                        {
                            target = ent; //set target to entity
                            if (distance < atkRange)  //and if entity is within attack range
                            {

                                if(count->Check()) //still not sure what this does...
                                {
                                    qDebug()<<"Attacking2";
                                    //State Calculations here
                                    if(Attack()) //prolly set up wrong
                                    {
                                        target = NULL; //set target to null
                                    }
                                }

                            }
                            else //if entity is within detection range but not attack range
                            {
                                //Magical Math that Moves!
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
            }else //if player is alive, not moving, and the target is null.
                //This looks suspiciously like repititon, Joel!
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
                                qDebug()<<"Attacking3";
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
        if(currentState != state) //if player is alive and state changes
        {
            state = currentState; //update state
            stateChange = true;   //tell someone about it
        }
    }
    else //if player is not alive
    {
        if(count->Check()) //STILL not sure what this does...
        {
            Alive = true; //Bring him to life!!!
            positionChange = true;
            stateChange = true;
            healthChange = true;
            curHealth = maxHealth;
            state = 5;
            if(team == 1) //Move him, based on team
            {
                x = 250;
                y = 2700;
            }
            else
            {
                x = 250;
                y = 2700;
            }
            count->reset(50/atkSpeed); //do something.... Not sure what
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
    curHealth = maxHealth;
    count->reset(250);
}

void PlCh::respawn()
{

}

bool PlCh::Attack()
{
    //qDebug() << target->getAttackable();
    int t = target->getType();
    if(t ==1)
    {
        qDebug()<<"Core";
    }
    else if (t ==2)
    {
        qDebug()<<"Tower";
    }
    else if (t ==3)
    {
        qDebug()<<"Minion";
    }
    else
    {
        qDebug()<<".....We didn't code this yet......";
    }
    if (target->getAttackable() == true)
    {
        return target->damage(atkDamage);
    }
    return false;

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
