#include "entity.h"
#include "world.h"
#include "core.h"

#include <string>
#include <sstream>

Core::Core(int cTeam, int newX, int newY, World *newMap)
{
    map = newMap;
    x = newX;
    y = newY;
    curHealth = 999;
    maxHealth = 999;
    healthChange = false;
    isNew = true;
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
//Bools: isNew, healthChange;
    stringstream strm;
    if(isNew)
    {
        strm<<" "<<(type * 10 + 1)<<" "<<absoluteID<<" "<<team<<" "<<((curHealth * 100) / maxHealth)<<" "<<0<<" "<<x<<" "<<y<<" "<<"NOT";
        isNew = false;
        healthChange = false;
    }
    else if(!isNew && healthChange)
    {
        strm<<" "<<(type * 10 + 5)<<" "<<absoluteID<<" "<<((curHealth * 100) / maxHealth);
        healthChange = false;
    }
    return strm.str();
}

