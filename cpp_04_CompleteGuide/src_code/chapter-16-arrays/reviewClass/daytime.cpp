#include "daytime.h"
#include <iostream>

DayTime::DayTime()
: hour(0), minute(0), second(0)
{}

DayTime::DayTime(const DayTime& z)
: hour(z.hour), minute(z.minute), second(z.second)
{}

DayTime::DayTime(int h, int m, int s)
{
    if(!setTime(h, m, s))
        hour = minute = second = 0;
}

bool DayTime::setTime(int hour, int minute, int second)
{
    if(   hour   >= 0 && hour   <= 24
       && minute >= 0 && minute <= 60
       && second >= 0 && second <= 60)
    {
        this->hour   = (short)hour;
        this->minute = (short)minute;
        this->second = (short)second;
        return true;
    }
    else
        return false;
}

DayTime::~DayTime()
{
    std::cout << hour << ":" << minute << ":" << second << " is destroyed" << std::endl;
}

int DayTime::asSeconds() const
{ return (60*60*hour + 60*minute + second); }

bool DayTime::isEqual(const DayTime& z) const
{ return (this->asSeconds() == z.asSeconds()); }

bool DayTime::isLess(const DayTime& z) const
{ return (this->asSeconds() < z.asSeconds()); }

void DayTime::print() const
{
    std::cout << hour << ':' << minute << ':' << second << std::endl;
}


