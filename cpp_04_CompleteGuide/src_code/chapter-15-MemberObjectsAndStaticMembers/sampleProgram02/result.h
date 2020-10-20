#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include <iostream>
#include <iomanip>
#include "daytime.h"

DayTime& currentTime(void);

class Result
{
    private:
        double val;
        const DayTime time;
    public:
        // constructor declaration
        Result();
        Result(double w, DayTime& z = currentTime());
        Result(double w, int hr, int mn, int sec);
        // destructor
        ~Result(){}
        // print
        void print() const
        {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "val: " << val << '\t';
            time.print();
        }
        // getter
        double getVal()          const { return val; }
        const DayTime& getTime() const { return time; }
        // setter
        void setVal(double w)    { val = w; }
        // void setTime(DayTime& z) { time = z; }
};

#endif // RESULT_H_INCLUDED
