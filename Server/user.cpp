#include "user.h"

//NEEDS BUNCHES OF WORK

User::User()
{
    userName = "";
    team = 7;
}

void User::command(std::string cmdString)
{

}

bool User::checkInstanceVars()
{
    if(userName == ""||team == 7)
    {
        return false;
    }
    return true;
}
