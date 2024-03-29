#ifndef TOWER_H
#define TOWER_H

class World;
class Entity;
class Unit;

class Tower : public Unit
{
    Tower();
public:
    Tower(int cTeam, int newX, int newY, World* newMap);
    virtual bool damage(int value);
    virtual void onTick();
    virtual string save();
    virtual Entity* load(std::string loadString);
    virtual string displayString();
    virtual void die();
    virtual bool Attack();
    World* world;
};

#endif // TOWER_H
