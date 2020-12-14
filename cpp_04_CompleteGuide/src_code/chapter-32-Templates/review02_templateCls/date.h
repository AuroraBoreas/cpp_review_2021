#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using std::string;
using std::stringstream;
using std::ostream;
using std::cout;

inline bool isLeapYear(unsigned int year)
{
    return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}

class Date
{
private:
    unsigned int year, month, day;
public:
    // constructor
    Date()
    {
        year = month = day = 1;
    }
    Date(unsigned int y,
         unsigned int m,
         unsigned int d)
    {
        if(!setDate(y, m, d))
            Date();
        year  = y;
        month = m;
        day   = d;
    }

    bool setDate(unsigned int y,
                 unsigned int m,
                 unsigned int d)
    {
        if(m<0 || m>12) return false;
        if(d<0 || d>31) return false;
        switch(m)
        {
            case 2: if(isLeapYear(y))
                    {
                        if(d>29) return false;
                    }
                    else
                        if(d>28) return false;
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if(d>31) return false;
        }
        return true;
    }
    void setDate(void)
    {
        struct tm *tm;
        time_t sec; std::time(&sec);
        tm = std::localtime(&sec);

        year  = (unsigned int)tm->tm_year + 1900;
        month = (unsigned int)tm->tm_mon + 1;
        day   = (unsigned int)tm->tm_mday;
    }
    // destructor
    virtual ~Date(){}
    // getter
    unsigned int getYear(void)  const { return year; }
    unsigned int getMonth(void) const { return month; }
    unsigned int getDay(void)   const { return day; }
    // setter
    void setYear(unsigned int y)  { year = y; }
    void setMonth(unsigned int m) { month = m; }
    void setDay(unsigned int d)   { day = d; }
    // repr
    string asString(void) const
    {
        stringstream ss;
        const char ch = '0';
        ss << std::setw(4) << std::setfill(ch) << year << "/"
           << std::setw(2) << std::setfill(ch) << month << "/"
           << std::setw(2) << std::setfill(ch) << day;
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
        if(year != d.year)        return (year < d.year);
        else if(month != d.month) return (month < d.month);
        else                      return (day < d.day);
    }
    // ...
};

#endif // DATE_H_INCLUDED
