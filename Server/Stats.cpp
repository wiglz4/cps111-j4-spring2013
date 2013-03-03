#include "Stats.h"

string Stats::toString()
{
    stringstream strm;
    strm << "6" <<" " << mKills << " " << mKills * minionPoints << " " << tKills << " " << tkills * towerPoints << " " << deaths << " " << deaths * deathPoints << " " << mKills * minionPoints + tKills * towerPoints + deaths * deathPoints << " " << username;
    return strm.str();
}
