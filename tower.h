#ifndef TOWER_H
#define TOWER_H

#include "unit.h"

class Tower : public Unit
{
    string towerLabel;
    static int redId;
    static int blueId;

public:
    Tower(string cTeam);
};

#endif // TOWER_H
