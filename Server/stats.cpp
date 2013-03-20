#include "stats.h"

int Stats::minionPoints = 5;
int Stats::towerPoints = 50;
int Stats::deathPoints = -10;

string Stats::toString()
{
    stringstream strm;
    strm << tKills << " " << mKills << " " << pKills << " " << deaths;
    return strm.str();
}

Stats::Stats(string name):
    username(name),
    mKills(0),
    pKills(0),
    tKills(0),
    deaths(0)
{
}

bool Stats::runTests()
{
    qDebug() << "Tests started.";

    mKills = 0;
    tKills = 0;
    deaths = 0;
    pKills = 0;

    assert (mKills == 0);
    assert (tKills == 0);
    assert (deaths == 0);

    incMKills();
    assert (mKills == 1);
    incTKills();
    assert (tKills == 1);
    incDeaths();
    assert (deaths == 1);

    string bob = toString();
    assert (bob == "6 1 5 1 50 1 -10 45 bob");

    incMKills();
    incTKills();
    bob = toString();
    assert (bob == "6 2 10 2 100 1 -10 100 bob");

    incDeaths();
    bob = toString();
    assert (bob == "6 2 10 2 100 2 -20 90 bob");
    return true;
}
