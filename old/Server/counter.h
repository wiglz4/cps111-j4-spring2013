#ifndef COUNTER_H
#define COUNTER_H

class Counter
{


public:
    Counter(int end);

    //returns true if the counter hits its limit, then resets.  returns false otherwise
    bool Check();

    //changes the limit of the counter
    void reset(int newEnd);

    //sets current to limit
    void reset();

    int current;
    int endint;
};

#endif // COUNTER_H
