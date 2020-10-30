#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include "daytime.h"
#include <string>
using namespace std;

class Result
{
    private:
        double val;
        DayTime time;
    public:
        // constructors
        // getter
        // setter
        friend class ControlPoint;
};

class ControlPoint
{
    private:
        string name;
        Result measure[100];
        // ...
    public:
        // constructor and methods
        // ...
        bool statistic(); // can access the private members of measure[i]

};

#endif // RESULT_H_INCLUDED
