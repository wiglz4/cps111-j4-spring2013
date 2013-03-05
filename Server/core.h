#ifndef CORE_H
#define CORE_H
#include "Entity.h"
#include "world.h"

class Core : public Entity
{
public:
    Core(int cTeam, int cX, int cY, World *newMap);
    void endGame();
    virtual bool damage(int value);
    virtual void onTick();
    virtual string save();
    virtual Entity* load();
    virtual string displayString();

};

#endif // CORE_H
