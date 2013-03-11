#include "stats.h"

int Stats::minionPoints = 5;
int Stats::towerPoints = 50;
int Stats::deathPoints = -10;

string Stats::toString()
{
    stringstream strm;
    strm << "6" <<" " << mKills << " " << mKills * minionPoints << " " << tKills << " " << tKills * towerPoints << " " << deaths << " " << deaths * deathPoints << " " << mKills * minionPoints + tKills * towerPoints + deaths * deathPoints << " " << username;
    return strm.str();
}

bool Stats::runTests()
{
    qDebug() << "Tests started.";

    mKills = 0;
    tKills = 0;
    deaths = 0;

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
