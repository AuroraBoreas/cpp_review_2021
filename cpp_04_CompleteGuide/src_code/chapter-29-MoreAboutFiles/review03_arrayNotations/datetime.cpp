#include "datetime.h"
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

DateTime::DateTime()
{
    hour = minute = second = 0;
}

DateTime::DateTime(int h, int m, int s)
{
    if(!setDateTime(h, m, s))
        DateTime();
}

bool DateTime::setDateTime(int hour, int minute, int second)
{
    if(   hour>=0 && hour<24
       && minute>=0 && minute<60
       && minute>=0 && minute<60)
    {
        this->hour   = (short)hour;
        this->minute = (short)minute;
        this->second = (short)second;
        return true;
    }
    return false;
}

void DateTime::setDateTime(void)
{
    struct tm *tm;
    time_t sec; time(&sec);
    tm = localtime(&sec);

    this->hour   = (short)tm->tm_hour;
    this->minute = (short)tm->tm_min;
    this->second = (short)tm->tm_sec;
}

int DateTime::asSeconds(void) const
{
    return (hour*60*60 + minute*60 + second);
}

bool DateTime::operator==(const DateTime& d)
{
    return (this->asSeconds() == d.asSeconds());
}

bool DateTime::operator<(const DateTime& d)
{
    return (this->asSeconds() < d.asSeconds());
}

string DateTime::asString(void) const
{
    stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hour   << ":"
       << std::setw(2) << std::setfill('0') << minute << ":"
       << std::setw(2) << std::setfill('0') << second;
    return ss.str();
}
