#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include "daytime.h"

class Result
{
    private:
        double val;
        const DayTime time;
        static int    cntObj;
        static double min;
        static double max;
        static bool   first;
        static void   setMinMax(double);
    public:
        // declare constructor
        Result(); // default
        Result(const Result&); // copy constructor
        Result(double, const DayTime&); // specific
        // declare destructor
        ~Result();
        // bool setTime(const DayTime&);
        // getter
        double getVal(void)          const { return val; }
        const DayTime& getTime(void) const { return time; }
        static double getMin(void)  { return min; }
        static double getMax(void)  { return max; }
        // setter
        void setVal(double w)        { val = w; }
        static void setMin(double w) { min = w; }
        static void setMax(double w) { max = w; }
        // print
        void print(void) const;
};

#endif // RESULT_H_INCLUDED
