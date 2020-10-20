#ifndef RESULT3_H_INCLUDED
#define RESULT3_H_INCLUDED

#include <iostream>
#include "daytime.h"

DayTime& currentTime(void);

class Result
{
private:
    double val;
    const DayTime time;
    static double min, max;
    static bool first;
    void setMinMax(double w);
public:
    Result(double w, const DayTime& z = currentTime());
    Result(double w, int hr, int mn, int sec);
    ~Result() {}
    // getter
    double getVal() const { return val; }
    // setter
    void setVal(double w) { val = w; }
    // print
    void print() const
    {
        std::cout << "val: " << val << '\t';
        time.print();
    }
};

#endif // RESULT3_H_INCLUDED
