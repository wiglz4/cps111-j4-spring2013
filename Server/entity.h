#ifndef ENTITY_H
#define ENTITY_H

#include <cmath>
#include <string>

class World;

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
    bool isNew;
    int team;
    int absoluteID;
    bool targetable;
    bool attackable;
    int size; //radius
    int type;

public:

    Entity() {}
    virtual bool damage(int value) = 0;
    virtual void onTick() = 0;
    virtual std::string save() = 0;
    virtual Entity* load(std::string loadString) = 0;
    virtual std::string displayString() = 0;
    int getCHealth(){return curHealth;}
    int getMHealth(){return maxHealth;}
    int getSize() {return size;}
    int getTeam() {return team;}
    bool getTargetable(){return targetable;}
    bool getAttackable(){return attackable;}
    int getType(){return type;}
    int getX(){return x + size;}
    int getY(){return y + size;}
    int getID(){return absoluteID;}

    void setCHEALTH(int newHealth){curHealth = newHealth;}
    void setMHEALTH(int newHealth){maxHealth = newHealth;}
    void setTargetable(bool newState){targetable = newState;}
    void setAttackable(bool newState){attackable = newState;}

};

#endif // ENTITY_H

