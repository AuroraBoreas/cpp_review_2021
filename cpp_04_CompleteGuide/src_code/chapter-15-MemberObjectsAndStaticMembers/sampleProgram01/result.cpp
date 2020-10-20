#include "daytime.h"
#include "result.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Result::Result()
{
    val = 0.0;
}

Result::Result(double w, const DayTime& z)
{
    val = w; time = z;
}

Result::Result(double w, int hr, int min, int sec)
{
    val = w;
    time = DayTime(hr, min, sec);
}

void Result::print() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "val = " << val << std::endl;
    time.print();
}

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

