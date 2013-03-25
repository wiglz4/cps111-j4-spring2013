#ifndef WORLD_H
#define WORLD_H

//NEEDS SOME WORK

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Game;
class Entity;
class Tower;
class Minion;
class PlCh;
class TowerShots;
class User;
class Counter;

using namespace std;

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

    vector<TowerShots *> shots;

    int tick;

    bool isNewGame;

    Game *game;

    Counter *count;

    Minion *aMinion;

    World();
public:
    World(vector<User *> *vect, Game* gam);

    //returns aPressedpointer to the nearest available enemy, All parameters come from the attacker
    Entity* getNAE(int x, int y, int team, double &distance);

    //performs bounds check against all walls, towers, and cores, returns false if outside of movable space
    bool boundsCheck(int x, int y);

    Entity* getByID(int entID);

    void onTick();

    void spawn();

    void save();

    static World* load(vector<User *> *vect, Game* gam);

    void incTick(){tick++;}
    void setTick(int i){tick = i;}

    void createRedMinion();
    void createBlueMinion();

    string Display();

    //Team denotes the losing side
    void endGame(int team);

    Entity *bob;

};

#endif // WORLD_H
