#ifndef STATS_H
#define STATS_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Stats
{
private:
    static int minionPoints;
    static int towerPoints;
    static int deathPoints;

    string UName;
    int mKills;
    int tKills;
    int deaths;

public:
    Stats(string name):Uname(name){}
    void incMKills(){++mKills;}
    void incTKills(){++tKills;}
    void incDeaths(){++deaths;}
    string toString();
};

#endif // STATS_H
