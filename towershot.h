#ifndef TOWERSHOT_H
#define TOWERSHOT_H

#include "minion.h"
#include "plch.h"
#include "entity.h"

class towerShot
{
    int x,y,delay;
    bool display;
    bool alive;
    double speed;
    Entity* target;


public:
    towerShot(int orgX, int orgY) {x = orgX; y = orgY;}
    void dec(){--delay; if(delay == 0) { display = true;}}
    bool getDisplay(){return display;}
    void onTick();
    bool getAlive(){return alive;}

};

#endif // TOWERSHOT_H
