#include "world.h"
#include "entity.h"
#include "unit.h"
#include "plch.h"
#include "user.h"

//NEEDS BUNCHES OF WORK

User::User()
{
    userName = "";
    team = 7;
}

void User::command(std::string cmdString)
{
    character->command(cmdString);
}

bool User::checkInstanceVars()
{
    if(userName == ""||team == 7)
    {
        return false;
    }
    return true;
}

QString User::score()
{
    QString s = QString::fromStdString(userName);
    s.remove(s.size() - 3);
    s = s + " " + QString::number(team) + " ";
    string stats = character->getStats();
    s = s + QString::fromStdString(stats);
    qDebug() << s;
    return s;
}
