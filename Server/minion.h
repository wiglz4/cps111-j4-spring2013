#ifndef MINION_H
#define MINION_H

class World;
class Entity;
class Unit;
class Counter;

class Minion : public Unit
{
    Minion();
protected:
    int cpX;
    int cpY;
    int laneX;
    int laneY;

    //OUT OF LANE
    bool OOL;
public:
    Minion(int cTeam, int newX, int newY, World *newMap);

    //damages this minion, returns true if the health drops to or below 0. returns false otherwise
    virtual bool damage(int value);

    //performs ai actions
    virtual void onTick();

    //returns a string containing the information needed to reload this minion
    virtual string save();

    //reloads a minion from an earlier game match
    virtual Entity* load();
    virtual string displayString();

    //changes attirubutes representing its abilities
    virtual void die();

    //sends damage to the target
    virtual bool Attack();

    virtual void getState();
};

#endif // MINION_H
