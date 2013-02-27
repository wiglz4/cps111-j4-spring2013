#ifndef CORE_H
#define CORE_H
#include "Entity.h"

class Core : public Entity
{
public:
    Core(string cTeam, int cX, int cY);
    void endGame();
};

#endif // CORE_H
