#ifndef MINION_H
#define MINION_H

class World;
class Entity;
class Unit;

class Minion : public Unit
{
protected:
    int cpX;
    int cpY;
    int laneX;
    int laneY;

    //OUT OF LANE
    bool OOL;
public:
    Minion(int cTeam, int newX, int newY, World *newMap);
    virtual bool damage(int value);
    virtual void onTick();
    virtual string save();
    virtual Entity* load();
    virtual string displayString();
    virtual void die();
    virtual bool Attack(Entity * ent);
};

#endif // MINION_H
