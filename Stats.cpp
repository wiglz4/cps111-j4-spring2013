#include "stats.h"

string Stats::toString()
{
    stringstream strm;
    strm << "{STATS}" << UName << "{:}" << mKills << "{:}" << tKills << "{:}" << deaths << "{/STATS}";
    return strm.str();
}
