#ifndef DYNAUNIT_H
#define DYNAUNIT_H
#include "unit.h"
class DynaUnit : public Unit
{
protected:
    double speed;
    bool canMove;
    bool updatePosition;
public:
    virtual bool damage(int value) = 0;
    virtual void onTick() = 0;
    virtual string save() = 0;
    virtual static Entity* load() = 0;
    virtual string displayString();
    virtual void die() = 0;
    bool Attack() = 0;
    void Move(int newX, int newY) = 0;
};

#endif // DYNAUNIT_H
