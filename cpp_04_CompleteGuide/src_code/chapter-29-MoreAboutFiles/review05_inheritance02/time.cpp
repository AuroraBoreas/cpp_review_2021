#include "time.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

Time::Time(void)
{
    hour = minute = second = 0;
}

Time::Time(int h, int m, int s)
{
    if(!setTime(h, m, s))
        Time();
}

bool Time::setTime(int hour, int minute, int second)
{
    if(   hour>=0   && hour <=24
       && minute>=0 && minute<=60
       && minute>=0 && minute<=60)
    {
        this->hour   = (short)hour;
        this->minute = (short)minute;
        this->second = (short)second;
        return true;
    }
    return false;
}

void Time::setTime(void)
{
    struct tm *tm;
    time_t sec; time(&sec);
    tm = localtime(&sec);

    hour   = (short)tm->tm_hour;
    minute = (short)tm->tm_min;
    second = (short)tm->tm_sec;
}

string Time::asString(void) const
{
    stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hour   << ":"
       << std::setw(2) << std::setfill('0') << minute << ":"
       << std::setw(2) << std::setfill('0') << second;
    return ss.str();
}

int Time::asSeconds(void) const
{
    return (hour*60*60 + minute*60 + second);
}

bool Time::operator==(const Time& t)
{
    return (this->asSeconds() == t.asSeconds());
}

bool Time::operator<(const Time& t)
{
    return (this->asSeconds() < t.asSeconds());
}
