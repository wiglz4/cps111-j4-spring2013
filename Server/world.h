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
#include "game.h"
#include "user.h"

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

    Game *game;
public:
    World(int numPlayers, int numRed, Game* thisGame);

    //returns a pointer to the nearest available enemy, All parameters come from the attacker
    Entity* getNAE(Entity *ent);

    //performs bounds check against all walls, towers, and cores, returns false if outside of movable space
    bool boundsCheck(Entity *ent);

    void onTick();

    string save();

    void load(string loadString);

    string Display();

    //Team denotes the losing side
    void endGame(int team);

};
#endif // WORLD_H
