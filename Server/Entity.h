#ifndef ENTITY_H
#define ENTITY_H

#include "world.h"
#include "Stats.h"

class Entity
{
protected:
    World *map;
    static int curID;
    int x;
    int y;
    int curHealth;
    int maxHealth;
    bool healthChange;
    int team;
    int absoluteID;
    bool targetable;
    bool attackable;
    int size; //radius
    int type;

public:
    virtual bool damage(int value) = 0;
    virtual void onTick() = 0;
    virtual string save() = 0;
    virtual static Entity* load() = 0;
    virtual string displayString();

    int getCHealth(){return curHealth;}
    int getMHealth(){return maxHealth;}
    int getSize() {return size;}
    int getTeam() {return team;}
    bool getTargetable(){return targetable;}
    bool getAttackable(){return attackable;}
    int getType(){return type;}
    int getX(){return x;}
    int getY(){return y;}
    int getID(){return absoluteID;}
    //int getSector(){return sectorID;}

    void setTargetable(bool newState){targetable = newState;}
    void setAttackable(bool newState){attackable = newState;}
    void setMap(World *newMap){map = newMap;}
};

int Entity::curID = 0;
#endif // ENTITY_H
