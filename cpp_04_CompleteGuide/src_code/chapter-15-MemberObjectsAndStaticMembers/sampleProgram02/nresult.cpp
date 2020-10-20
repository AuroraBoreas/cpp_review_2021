#include "result.h"
#include "daytime.h"
#include <ctime>

Result::Result() : val(0.0) {}
Result::Result(double w, DayTime& z) : val(w), time(z) {}
Result::Result(double w, int hr, int mn, int sec) : val(w), time(hr, mn, sec) {}

DayTime& currentTime()
{
    static DayTime curTime;
    time_t sec; time(&sec);
    struct tm* time = localtime(&sec);
    curTime.setTime(time->tm_hour,
                    time->tm_min,
                    time->tm_sec);
    return curTime;
}
