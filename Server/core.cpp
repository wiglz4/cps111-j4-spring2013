#include "entity.h"
#include "world.h"
#include "core.h"

#include <string>

Core::Core(int cTeam, int newX, int newY, World *newMap)
{
    map = newMap;
    x = newX;
    y = newY;
    curHealth = 999;
    maxHealth = 999;
    healthChange = true;
    team = cTeam;
    absoluteID = ++curID;
    targetable = true;
    attackable = true;
    size = 200; //radius
    type = 1;

}

void Core::endGame()
{
    map->endGame(team);
}

bool Core::damage(int value)
{
    curHealth = curHealth - value;
    if(curHealth < 0)
    {
        endGame();
    }
    return false;
}
void Core::onTick()
{
//FINE AS IS
}

string Core::save()
{
//NEEDS CODING
}

Entity* Core::load()
{
//NEEDS CODING
}

string Core::displayString()
{
//NEEDS CODING
}

