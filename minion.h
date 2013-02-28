#ifndef MINION_H
#define MINION_H
#include "dynaunit.h"
class Minion : public DynaUnit
{
protected:
    int cpX;
    int cpY;

    //OUT OF LANE
    bool OOL;
public:
    Minion(int cTeam, int newX, int newY, World *newMap);
};

#endif // MINION_H
