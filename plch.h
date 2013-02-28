#ifndef PLCH_H
#define PLCH_H
#include "dynaunit.h"
class PlCh
{
protected:
    string plName;
    Stats points;
    bool underCommand;

    //int level;
    //int experience;
    //int experienceBound;

public:
    PlCh(string cTeam, int pX, int pY);
    void command(string cmdString);
//void levelUp();
};

#endif // PLCH_H
