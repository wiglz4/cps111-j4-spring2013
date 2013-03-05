#ifndef MINION_H
#define MINION_H
class Minion;
#include "unit.h"
class Minion : public Unit
{
protected:
    int cpX;
    int cpY;
    int laneX;
    int laneY;

    //OUT OF LANE
    bool OOL;
public:
    Minion(int cTeam, int newX, int newY, World *newMap);
};

#endif // MINION_H
