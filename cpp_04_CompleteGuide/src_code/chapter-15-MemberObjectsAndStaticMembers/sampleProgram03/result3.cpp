#include "result3.h"
#include "daytime.h"
#include <ctime>

double Result::min = 0.0;
double Result::max = 0.0;
bool   Result::first = true;
void   Result::setMinMax(double w)
{
    if(first) { min = max = w; first = false; }
    else if(w < min)
        min = w;
    else if(w > max)
        max = w;
}

// constructors with member initializers
Result::Result(double w, const DayTime& z) : val(w), time(z)
{ setMinMax(w); }
Result::Result(double w, int hr, int mn, int sec) : val(w), time(hr, mn, sec)
{ setMinMax(w); }


DayTime& currentTime()
{
    static DayTime curTime;
    time_t sec; time(&sec);
    struct tm *time = localtime(&sec);
    curTime.setTime(time->tm_hour,
                    time->tm_min,
                    time->tm_sec);
    return curTime;
}
