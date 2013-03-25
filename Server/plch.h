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

    PlCh();

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

    //changes button-pressed booleans based upon <cmdString>
    void command(string cmdString);

    //returns the necessary stats information
    string getStats();

    //changes various characterstics to render the character invincible
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
    World* world;
};

#endif // PLCH_H
