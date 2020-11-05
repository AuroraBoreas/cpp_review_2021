#include "daytime.h"
#include <ctime>

using namespace std;

DayTime::DayTime()
{
    hour = minute = second = 0;
}

DayTime::DayTime(int h, int m, int s)
{
    if(!setDayTime(h, m, s))
        hour = minute = second = 0;
}

bool DayTime::setDayTime(int hour, int minute, int second)
{
    if(   hour>=0 && hour<=24
       && minute>=0 && minute<=60
       && second>=0 && second<=60)
    {
        this->hour   = (short)hour;
        this->minute = (short)minute;
        this->second = (short)second;
        return true;
    }
    return false;
}

void DayTime::setDayTime(void)
{
    struct tm *tm;
    time_t sec; time(&sec);
    tm = localtime(&sec);

    hour = tm->tm_hour;
    minute = tm->tm_min;
    second = tm->tm_sec;
}

DayTime::~DayTime()
{
    //...
}

int DayTime::asSeconds(void) const
{
    return (60*60*hour + 60*minute + second);
}

bool DayTime::isEqual(const DayTime& dt) const
{
    return this->asSeconds() == dt.asSeconds();
}

bool DayTime::isLess(const DayTime& dt) const
{
    return this->asSeconds() < dt.asSeconds();
}
