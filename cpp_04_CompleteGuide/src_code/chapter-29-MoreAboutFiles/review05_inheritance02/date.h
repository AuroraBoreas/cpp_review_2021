#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include "time.h"
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

inline bool isLeapYear(int year)
{
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}

class Date
{
private:
    short year, month, day;
public:
    // constructor
    Date(){ year = month = day = 1; }
    Date(int y, int m, int d)
    {
        if(!setDate(y, m, d))
            Date();
        year  = (short)y;
        month = (short)m;
        day   = (short)d;
    }
    bool setDate(int y, int m, int d)
    {
        if(m < 1 || m > 12) return false;
        if(d < 1 || d > 31)     return false;
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
    void setDate(void)
    {
        struct tm *tm;
        time_t sec; time(&sec);
        tm = localtime(&sec);

        this->year  = (short)tm->tm_year + 1900;
        this->month = (short)tm->tm_mon + 1;
        this->day   = (short)tm->tm_mday;

    }
    // destructor
    virtual ~Date(){}
    // getter
    short getYear(void)  const { return year; }
    short getMonth(void) const { return month; }
    short getDay(void)   const { return day; }
    // setter
    void setYear(int y)  { if(y>=1) year = y; }
    void setMonth(int m) { if(m>=1 && m<=12) month = m; }
    void setDay(int d)   { if(d>=1 && d<=31) day = d; }
    // repr
    string asString(void) const
    {
        stringstream ss;
        ss << std::setw(4) << std::setfill('0') << year  << "/"
           << std::setw(2) << std::setfill('0') << month << "/"
           << std::setw(2) << std::setfill('0') << day;
        return ss.str();
    }
    friend ostream& operator<<(ostream& os, const Date& d)
    {
        os << d.asString();
        return os;
    }
    // comparison
    bool operator==(const Date& d)
    {
        return (year == d.year && month == d.month && day == d.day);
    }
    bool operator<(const Date& d)
    {
        if(year != d.year)        return year < d.year;
        else if(month != d.month) return month < d.month;
        else                      return day < d.day;
    }

};

#endif // DATE_H_INCLUDED
