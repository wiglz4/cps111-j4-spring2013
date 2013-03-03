#ifndef TOWERSHOT_H
#define TOWERSHOT_H

#include "minion.h"
#include "plch.h"
#include "Entity.h"
#include <string>

class towerShot
{
    int x,y,delay;
    bool display;
    bool alive;
    double speed;
    Entity* target;


public:
    towerShot(int orgX, int orgY) {x = orgX; y = orgY; delay = 10;}
    void dec(){--delay; if(delay == 0) { display = true;}}
    string DispShot();
    void onTick();
    bool getAlive(){return alive;}

};

#endif // TOWERSHOT_H
