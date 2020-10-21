#include "result4.h"
#include <iostream>
#include <iomanip>

// definitions of static data members
double Result::min   = 0.0;
double Result::max   = 0.0;
bool   Result::first = true;
void   Result::setMinMax(double w)
{
    if(first) { min = max = w; first = false; }
    else if(w < min) min = w;
    else if(w > max) max = w;
}
// definitions of constructors to initialize non-static members;
Result::Result() : val(0.0) { /* ... */ }
Result::Result(double w): val(w) { setMinMax(w); }
Result::Result(double w, const DayTime& z)
: val(w), time(z)
{
    setMinMax(w);
}
Result::Result(double w, int h, int m, int s)
: val(w), time(h, m, s)
{
    setMinMax(w);
}
// definition of other methods
void Result::print() const
{
    std::cout << "val : " << std::fixed << std::setprecision(2) << val << '\t';
    std::cout << "time: ";
    time.print();
    std::cout << std::endl;
}
