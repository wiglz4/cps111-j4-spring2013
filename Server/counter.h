#ifndef COUNTER_H
#define COUNTER_H

class Counter
{


public:
    Counter(int end);
    bool Check();
    void reset(int newEnd);
    void reset();
    int current;
    int endint;
};

#endif // COUNTER_H
