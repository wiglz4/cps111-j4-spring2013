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

    bool w;
    bool a;
    bool s;
    bool d;

    //int level;
    //int experience;
    //int experienceBound;

public:
    PlCh(int cTeam, int newX, int newY, World *newMap, string pName);
    void command(string cmdString);
    string getStats(){return points->toString();}
    void cheatMode();
    void setName(string newName){plName = newName;}
//void levelUp();
};

#endif // PLCH_H
