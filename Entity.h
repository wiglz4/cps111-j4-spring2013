#ifndef ENTITY_H
#define ENTITY_H

#include "Stats.h"

class Entity
{
protected:
    static int curID;
    int curHealth;
    int maxHealth;
    string team;
    bool targetable;
    bool attackable;
    int x;
    int y;
    int size; //radius
    string type;
    int absoluteID;
    //int sectorID;

public:
    virtual bool damage(int value) = 0;
    virtual void onTick() = 0;

    int getCHealth(){return curHealth;}
    int getMHealth(){return maxHealth;}
    int getSize() {return size;}
    string getTeam() {return team;}
    bool getTargetable(){return targetable;}
    bool getAttackable(){return attackable;}
    string getType(){return type;}
    int getX(){return x;}
    int getY(){return y;}
    int getID(){return absoluteID;}
    //int getSector(){return sectorID;}

    void setTargetable(bool newState){targetable = newState;}
    void setAttackable(bool newState){attackable = newState;}
};

int Entity::curID = 0;
#endif // ENTITY_H
