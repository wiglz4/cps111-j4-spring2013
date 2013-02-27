#ifndef PLCH_H
#define PLCH_H
#include "dynaunit.h"
class PlCh
{
protected:
    string plName;
    int level;
    int experience;
    int experienceBound;
    Stats points;
public:
    PlCh(string cTeam, int pX, int pY);
//void levelUp();
};

#endif // PLCH_H
