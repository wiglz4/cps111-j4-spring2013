#ifndef UNIT_H
#define UNIT_H
#include "Entity.h"
#include "counter.h"
class Unit : public Entity
{
protected:
    int atkDamage;
    int atkSpeed;
    int armor;
    int atkRange;
    int detRange;
    bool canAttack;
    bool Alive;
    bool doneDie;
    //AI personal;
    Entity *target;
    Counter count;
    int targetPriority;
    string aiState;
    string animState;

public:
    virtual bool damage(int value) = 0;
    virtual void onTick() = 0;
    virtual void die() = 0;
    bool Attack() = 0;

    void setCanAttack(bool newState){canAttack = newState;}
    void setAlive(bool newState){Alive = newState;}

};

#endif // UNIT_H
