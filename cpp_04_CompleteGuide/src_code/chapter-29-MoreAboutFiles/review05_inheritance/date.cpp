#include "date.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

inline bool isLeapYear(int year)
{
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}

Date::Date()
{
    year = month = day = 1;
}

Date::Date(int y, int m, int d)
{
    if(!setDate(y, m, d))
        Date();
    year  = (short)y;
    month = (short)m;
    day   = (short)d;
}

bool Date::setDate(int y, int m, int d)
{
    if(m<1 || m>12) return false;
    if(d<1 || d>31) return false;
    switch(m)
    {
        case 2: if(isLeapYear(y))
                {
                    if(d>29) return false;
                }
                else if(d>28)
                    return false;
                break;
        case 4:
        case 6:
        case 9:
        case 11: if(d>30)
                {
                    return false;
                }
    }
    return true;
}

void Date::setDate(void)
{
    struct tm *tm;
    time_t sec; time(&sec);
    tm = localtime(&sec);

    this->year  = (short)tm->tm_year + 1900;
    this->month = (short)tm->tm_mon + 1;
    this->day   = (short)tm->tm_mday;
}

string Date::asString(void) const
{
    stringstream ss;
    ss << std::setw(4) << std::setfill('0') << year  << "-"
       << std::setw(2) << std::setfill('0') << month << "-"
       << std::setw(2) << std::setfill('0') << day;
    return ss.str();
}

bool Date::operator==(const Date& d)
{
    return (this->year == d.year && this->month == d.month && this->day == d.day);
}

bool Date::operator<(const Date& d)
{
    if(this->year != d.year)        return this->year < d.year;
    else if(this->month != d.month) return this->month < d.month;
    else                            return this->day < d.day;
}
