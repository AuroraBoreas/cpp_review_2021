#include "daytime.h"
#include "result.h"
#include <iostream>
#include <iomanip>

// private static data members
double Result::min    = 0;
double Result::max    = 0;
int    Result::cntObj = 0;
bool   Result::first  = false;
// static method
void Result::setMinMax(double w)
{
    if(first) { min = max = w; first = true; }
    else if(min > w) { min = w; }
    else if(max < w) { max = w; }
}

Result::Result()
: val(0.0)
{
    ++cntObj;
    std::cout << "this is No." << cntObj << " Result object" << std::endl;
}

Result::Result(const Result& z)
: val(z.val), time(z.time)
{
    setMinMax(z.val);
    ++cntObj;
    std::cout << "this is No." << cntObj << " Result object" << std::endl;
}

Result::Result(double w, const DayTime& z)
: val(w), time(z)
{
    setMinMax(w);
    ++cntObj;
    std::cout << "this is No." << cntObj << " Result object" << std::endl;
}

Result::~Result()
{
    std::cout << std::endl;
    std::cout << "No." << cntObj-- << " Result object is destroyed."
              << "there are " << cntObj << " left." << std::endl;
}

void Result::print() const
{
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "val : " << val << std::endl;
    std::cout << "time: ";
    time.print();
}
