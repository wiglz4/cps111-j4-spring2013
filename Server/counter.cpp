#include "counter.h"

Counter::Counter(int end)
{
    current = end;
    endint = end;
}

bool Counter::Check()
{
    if(current == endint)
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

void Counter::reset()
{
    current = endint;
}
