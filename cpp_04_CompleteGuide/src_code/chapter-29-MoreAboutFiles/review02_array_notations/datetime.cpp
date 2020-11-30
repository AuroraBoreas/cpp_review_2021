#include "datetime.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

DateTime::DateTime()
{
    hour = minute = second = 0;
}

DateTime::DateTime(int h, int m, int s)
{
    if(!setDate(h, m, s))
        DateTime();
}

bool DateTime::setDate(int hour, int minute, int second)
{
    if(   hour   >=0 && hour   <= 24
       && minute >=0 && minute <= 60
       && second >=0 && second <= 60)
    {
        this->hour   = (short)hour;
        this->minute = (short)minute;
        this->second = (short)second;
        return true;
    }
    return false;
}

void DateTime::setDate(void)
{
    struct tm *tm;
    time_t sec; time(&sec);
    tm = localtime(&sec);

    hour   = (short)tm->tm_hour;
    minute = (short)tm->tm_min;
    second = (short)tm->tm_sec;
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
    ss << setfill('0') << setw(2) << hour   << ":"
       << setfill('0') << setw(2) << minute << ":"
       << setfill('0') << setw(2) << second;
    return ss.str();
}
