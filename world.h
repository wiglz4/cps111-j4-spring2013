#ifndef WORLD_H
#define WORLD_H

#include <string>

using namespace std;

//A Pseudo-Singleton class
#include "Entity.h"
#include "Stats.h"
#include "core.h"
#include "counter.h"
#include "dynaunit.h"
#include "minion.h"
#include "plch.h"
#include "tower.h"
#include "unit.h"
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

    vector<bool> redAlive;
    vector<bool> blueAlive;

public:
    World(string cmdString);
    static World& instance() { return world; }
};

extern World world;
#endif // WORLD_H
