#ifndef STATS_H
#define STATS_H

#include <string>
#include <sstream>
#include <vector>
#include <QDebug>
#include <assert.h>
#include <QString>

using namespace std;

class Stats
{
private:
    string username;
    static int minionPoints;
    static int towerPoints;
    static int deathPoints;

    string UName;
    int mKills;
    int tKills;
    int deaths;
    int pKills;

    bool tests;

public:
    Stats(string name);
    void incMKills(){++mKills;}
    void incTKills(){++tKills;}
    void incDeaths(){++deaths;}
    bool runTests();

    string toString();
};

#endif // STATS_H
