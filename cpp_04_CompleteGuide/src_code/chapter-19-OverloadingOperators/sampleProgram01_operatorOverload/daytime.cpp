#include "daytime.h"
#include <iostream>

// static data member
int DayTime::objCounter = 0;
// default constructor
DayTime::DayTime()
{
    hour = minute = second = 0;
    objCounter++;
}
// copy constructor
DayTime::DayTime(const DayTime& z)
: hour(z.hour), minute(z.minute), second(z.second)
{ objCounter++; }
// parameterized constructor
DayTime::DayTime(int h = 0, int m = 0, int s = 0)
{
    if(!setTime(h, m, s))
        hour = minute = second = 0;
}
// constructor helper
bool DayTime::setTime(int hour, int minute, int second)
{
    if(   hour   >= 0 && hour   <= 24
       && minute >= 0 && minute <= 60
       && second >= 0 && second <= 60)
    {
        this->hour   = (short)hour;
        this->minute = (short)minute;
        this->second = (short)second;
        objCounter++;
        return true;
    }
    else
        return false;
}
// destructor
DayTime::~DayTime()
{
    std::cout << "\nDayTime object No." << objCounter-- << " is destroyed. ";
    std::cout << "there are " << objCounter << " objects left.\n";
}

// comparison methods
int DayTime::asSeconds(void) const
{ return (60*60*hour + 60*minute + second); }

bool DayTime::isEqual(const DayTime& z)
{ return (this->asSeconds() == z.asSeconds()); }

bool DayTime::isLess(const DayTime& z)
{ return (this->asSeconds() < z.asSeconds()); }

// print
void DayTime::print(void) const
{ std::cout << hour << ":" << minute << ":" << second << "\n"; }

// methods to overload operators
bool DayTime::operator<(const DayTime& z) const
{ return (this->asSeconds() < z.asSeconds()); }

DayTime& DayTime::operator++(void)
{
    second++;
    return *this;
}
