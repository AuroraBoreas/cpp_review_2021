#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <ctime>

inline bool isLeapYear(unsigned year)
{ return (year%4 == 0 && year%100 != 0) || year%400 == 0; }

class Date
{
private:
    unsigned year, month, day;
public:
    // constructor
    Date(){ year = month = day = 1; }; // default, user defined,
    Date(unsigned ye, unsigned mo, unsigned da) // regular,
    {
        if(!setDate(ye,mo,da))
            year = month = day = 1;
        year  = ye;
        month = mo;
        day   = da;
    }
    bool setDate(unsigned ye, unsigned mo, unsigned da)
    {
        if(ye <= 0) return false;
        if(mo <= 0 || mo > 12) return false;
        if(da <= 0 || da > 31) return false;
        switch(mo)
        {
            case 2: if(isLeapYear(mo))
                    {
                        if(da > 29) return false;
                    }
                    else
                    {
                        if(da > 28) return false;
                    }
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if(da > 30) return false;
        }

        return true;
    }
    void setDate(void)
    {
        struct tm *tm;
        time_t sec; std::time(&sec);
        tm = std::localtime(&sec);

        year  = tm->tm_year + 1930;
        month = tm->tm_mon + 1;
        day   = tm->tm_mday;
    }
    // getter
    [[nodiscard]] unsigned getYear(void)  const { return year; }
    [[nodiscard]] unsigned getMonth(void) const { return month; }
    [[nodiscard]] unsigned getDay(void)   const { return day; }
    // setter
    void setYear(unsigned ye)  { year = ye; }
    void setMonth(unsigned mo) { month = mo; }
    void setDay(unsigned da)   { day = da; }

    // repr
    friend std::ostream& operator<<(std::ostream& os, const Date& d)
    {
        os << std::setw(4) << std::setfill('0') << d.year << "/"
           << std::setw(2) << std::setfill('0') << d.month << "/"
           << std::setw(2) << std::setfill('0') << d.day;
        return os;
    }

};

#endif // DATE_H_INCLUDED
