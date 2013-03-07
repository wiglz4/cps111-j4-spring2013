#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
    int current;
    int endint;

public:
    Counter(int end);
    bool Check();
    void reset(int newEnd);
    void reset();
};

#endif // COUNTER_H
