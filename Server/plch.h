#ifndef PLCH_H
#define PLCH_H
#include "unit.h"
class PlCh : public Unit
{
protected:
    string plName;
    Stats *points;
    bool display;
    bool isCheatMode;
    bool canCheatMode;
    Counter cheatCounter;

    //int level;
    //int experience;
    //int experienceBound;

public:
    PlCh(int cTeam, int newX, int newY, World *newMap, string pName);
    void command(string cmdString);
    string getStats(){return Stats.toString();}
    void cheatMode();
//void levelUp();
};

#endif // PLCH_H
