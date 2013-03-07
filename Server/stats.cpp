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
