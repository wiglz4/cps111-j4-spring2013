#ifndef TOWERSHOTS_H
#define TOWERSHOTS_H
#include <string>

class Entity;

class TowerShots
{
    int x,y,delay;
    bool display;
    bool alive;
    double static speed;
    Entity* target;


public:
    TowerShots(int orgX, int orgY, Entity* targ) {x = orgX; y = orgY; delay = 10; target = targ; alive = true;}
    void dec(){--delay; if(delay == 0) { display = true;}}
    std::string DispShot();
    void onTick();
    bool getAlive(){return alive;}
};

#endif // TOWERSHOTS_H
