#include "Stats.h"

string Stats::toString()
{
    stringstream strm;
    strm << "{STATS}" << username << "{:}" << mKills << "{:}" << tKills << "{:}" << deaths << "{/STATS}";
    return strm.str();
}

//writes strings to file
void Stats::toFile()
{

}
