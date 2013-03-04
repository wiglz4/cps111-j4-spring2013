#include "counter.h"

Counter::Counter(int end)
{
    current = 0;
    endint = end;
}

bool Counter::Check()
{
    if(current = endint)
    {
        current = 0;
        return true;
    }
    else
    {
        ++current;
        return false;
    }
}

void Counter::reset(int newEnd)
{
    current = 0;
    endint = newEnd;
}
