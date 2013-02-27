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
    Stats(string name, string cclass):Uname(name),UClass(cclass){}
    void incMKills(){++mKills;}
    void incTKills(){++tKills;}
    void incDeaths(){++deaths;}

    int getMKills(){return mKills;}
    int getTKills(){return tKills;}
    int getDeaths(){return deaths;}
    string toString();
};

#endif // STATS_H
