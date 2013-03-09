#ifndef UNIT_H
#define UNIT_H

class Entity;
class Counter;

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
    bool newDead;
    Entity *target;
    Counter *count;
    int targetPriority;
    int state;
    bool stateChange;
    double speed;
    bool canMove;
    bool positionChange;


public:
    Unit() {}
    virtual bool damage(int value) = 0;
    virtual void onTick() = 0;
    virtual string save() = 0;
    virtual Entity* load() = 0;
    virtual string displayString() = 0;
    virtual void die() = 0;
    virtual bool Attack() = 0;



    void setCanAttack(bool newState);
    void setAlive(bool newState);
    void setSpeed(int newSpeed);

    bool getAlive(){return Alive;}
};

#endif // UNIT_H
