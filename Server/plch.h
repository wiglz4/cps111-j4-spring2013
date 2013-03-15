#ifndef PLCH_H
#define PLCH_H

class World;
class Entity;
class Unit;
class Stats;
class Counter;

class PlCh : public Unit
{
protected:
    string plName;
    Stats *points;
    bool display;
    bool isCheatMode;
    bool canCheatMode;
    Counter *cheatCounter;

    bool wPressed;
    bool aPressed;
    bool sPressed;
    bool dPressed;

    //int level;
    //int experience;
    //int experienceBound;

    //REM
    int debugCount;
    //REM

    bool debug;

public:
    PlCh(int cTeam, int newX, int newY, World *newMap, string pName);
    void command(string cmdString);
    string getStats();
    void cheatMode();
    void setName(string newName){plName = newName;}
    virtual bool damage(int value);
    virtual void onTick();
    virtual string save();
    virtual Entity* load();
    virtual string displayString();
    virtual void die();
    virtual void respawn();
    virtual bool Attack();

    //moves player character based on key press, returns new state
    virtual int moveManual();

    //moves player character based on target, returns new state
    //virtual int moveAutomatic() = 0;
};

#endif // PLCH_H
