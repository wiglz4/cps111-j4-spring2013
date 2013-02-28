#include "core.h"
//999 is an arbitrary, placeholder value;
Core::Core(string cTeam, int cX, int cY)
{

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

