#ifndef CORE_H
#define CORE_H
#include "Entity.h"
#include "world.h"
class World;

class Core : public Entity
{
public:
    Core(int cTeam, int cX, int cY, World *newMap);
    void endGame();
};

#endif // CORE_H
