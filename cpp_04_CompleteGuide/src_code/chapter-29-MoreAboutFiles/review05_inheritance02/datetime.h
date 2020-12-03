#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include "date.h"
#include "time.h"
#include <iostream>
using namespace std;

class DateTime:public Date, public Time
{
public:
    // constructor
    DateTime(): Date(), Time(){}
    DateTime(int yr, int mo, int da, int h, int m, int s)
    : Date(yr, mo, da), Time(h, m, s){}
    // setter
    void setDateTime(void)
    {
        /* idk why this doesn't work?
           i think i do know. constructor can't be initialize again via method...
        */
        // struct tm *tm;
        // time_t sec; time(&sec);
        // tm = localtime(&sec);

        // Date(tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
        // Time(tm->tm_hour, tm->tm_min, tm->tm_sec);
        Date::setDate();
        Time::setTime();
    }
    // repr
    void display(void) const
    {
        cout << Date::asString() << " ";
        cout << Time::asString() << "\n";
    }
    // comparison
    bool operator==(const DateTime& dt);
    bool operator<(const DateTime& dt);
};

inline bool DateTime::operator==(const DateTime& dt)
{
    return Date::operator==(dt) && Time::operator==(dt); // upcasting
}

inline bool DateTime::operator<(const DateTime& dt)
{
    if(!Date::operator==(dt)) return Date::operator<(dt); // upcasting
    else                      return Time::operator<(dt);
}


#endif // DATETIME_H_INCLUDED
