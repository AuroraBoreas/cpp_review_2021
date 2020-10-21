#ifndef RESULT4_H_INCLUDED
#define RESULT4_H_INCLUDED

#include <iostream>
#include "daytime.h"

class Result
{
private:
    double val;
    const DayTime time;
    static double min, max;
    static bool first;
    static void setMinMax(double w);
public:
    Result();
    Result(double);
    Result(double, const DayTime&);
    Result(double, int, int, int);
    ~Result(){}
    // getter
    double getVal(void)          const { return val; }
    const DayTime& getTime(void) const { return time; }
    // setter
    // void setTime(const DayTime& z)    { time = z; } // exception: why? because const data member only initialized only once in constructors
    // bool setTime(int h, int m, int s) { return time.setTime(h, m, s); }
    void print(void) const;
    static double getMin() { return min; }
    static double getMax() { return max; }

};

#endif // RESULT4_H_INCLUDED
