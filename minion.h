#ifndef MINION_H
#define MINION_H
#include "dynaunit.h"
class Minion : DynaUnit
{
protected:
    int cpX;
    int cpY;

    //OUT OF LANE
    bool OOL;
public:
    Minion(string cTeam, int mX, int mY);
};

#endif // MINION_H
