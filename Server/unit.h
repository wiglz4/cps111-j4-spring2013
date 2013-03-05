#ifndef UNIT_H
#define UNIT_H
#include "Entity.h"
#include "counter.h"
class Unit : public Entity
{
protected:
    int atkDamage;
    double atkSpeed;
    int armor;
    int atkRange;
    int detRange;
    bool canAttack;
    bool Alive;
    bool doneDie;
    Entity *target;
    Counter count;
    int targetPriority;
    string state;
    bool stateChange;
    double speed;
    bool canMove;
    bool positionChange;


public:
    Unit();
    virtual bool damage(int value) = 0;
    virtual void onTick() = 0;
    virtual string save() = 0;
    virtual Entity* load() = 0;
    virtual string displayString();
    virtual void die() = 0;
    virtual bool Attack(Entity * ent) = 0;


    void setCanAttack(bool newState);
    void setAlive(bool newState);
    void setSpeed(int newSpeed);

};

#endif // UNIT_H
