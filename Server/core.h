#ifndef CORE_H
#define CORE_H

class World;
class Entity;

class Core : public Entity
{
    Core();
public:
    Core(int cTeam, int cX, int cY, World *newMap);
    void endGame();

    //damages this core, returns true if the core's health drops to or below 0
    virtual bool damage(int value);

    //performs ai actions (for core, none)
    virtual void onTick();

    //returns a string containing the needed information to reload this entity
    virtual string save();

    //creates an entity from the data from a saved game, returns a pointer to this entity
    virtual Entity* load();

    //returns a string containing any necessary display information for this enitity
    virtual string displayString();
};

#endif // CORE_H
