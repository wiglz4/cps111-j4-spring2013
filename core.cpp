#include "core.h"
//999 is an arbitrary, placeholder value;
Core::Core(string cTeam, int cX, int cY)
{
    //Entity class values - replace where needed
    curHealth = 5000;
    maxHealth = 5000;
    team = cTeam;
    targetable = false;
    attackable = false;
    x = cX;
    y = cY;
    size = 999;//radius
    type = "{CORE}";
    absoluteID = ++curID;
    //int sectorID;

}

void Core::endGame()
{
    return false;
}

bool Core::damage(int value)
{
    health = health - value;
    if(health < 0)
    {
        endGame();
    }
    return false;
}
void Core::onTick()
{

}

