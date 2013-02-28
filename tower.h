#ifndef TOWER_H
#define TOWER_H

#include "unit.h"

class Tower : public Unit
{

public:
    Tower(string cTeam, int newX, int newY, World* newMap);
};

#endif // TOWER_H
