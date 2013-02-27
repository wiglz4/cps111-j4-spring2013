#ifndef MINION_H
#define MINION_H
#include "dynaunit.h"
class Minion : DynaUnit
{
protected:
    int checkPoint;
public:
    Minion(string cTeam, int mX, int mY);
};

#endif // MINION_H
