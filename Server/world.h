#ifndef WORLD_H
#define WORLD_H

#include <string>

using namespace std;

#include "Entity.h"
#include "Stats.h"
#include "core.h"
#include "counter.h"
#include "dynaunit.h"
#include "minion.h"
#include "plch.h"
#include "tower.h"
#include "unit.h"
#include "towershot.h"
#include <string>
#include <sstream>
#include <vector>

class World
{
private:
    vector<Entity *> redEntities;
    vector<Entity *> blueEntities;
    vector<Tower *> redTowers;
    vector<Tower *> blueTowers;
    vector<Minion *> redMinions;
    vector<Minion *> blueMinions;
    vector<PlCh *> redPlChs;
    vector<PlCh *> bluePlChs;

    vector<Entity *> allEntities;
    vector<Tower *> allTowers;
    vector<Minion *> allMinions;
    vector<PlCh *> allPlChs;

    vector<bool> redAlive;
    bool redVulnerable;

    vector<bool> blueAlive;
    bool blueVulnerable;

    vector<towerShot *> shots;
public:
    World(int numPlayers, int numRed, vector<string> names);

    Entity* getByID(int ID);

    //Sends a command to the player character with <ID>
    void plCom(int ID, string com);

    //returns a pointer to the nearest available enemy, All parameters come from the attacker
    Entity* getNAE(int locX, int locY, string origColor);

    //performs bounds check against all walls, towers, and cores, returns false if outside of movable space
    bool boundsCheck(int locX, int locY, int uSize);

    void onTick();

    string save();

    void load(string loadString);

    string Display();

};
#endif // WORLD_H
