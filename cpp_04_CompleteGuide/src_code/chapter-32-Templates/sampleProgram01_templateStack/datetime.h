#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include "date.h"
#include "time.h"
#include <string>
#include <sstream>
using namespace std;

class DateTime:public Date, public Time
{
public:
    // constructor
    DateTime()
    : Date(), Time() {}

    DateTime(unsigned int year,
             unsigned int month,
             unsigned int day,
             int hour,
             int minute,
             int second)
    : Date(year, month, day), Time(hour, minute, second){}

    void setDateTime(void)
    {
        // using inherited methods
        Date::setDate();
        Time::setTime();
    }
    // destructor
    virtual ~DateTime(){}
    // getter
    // setter
    // repr
    string asString(void) const
    {
        stringstream ss;
        ss << Date::asString() << " " << Time::asString();
        return ss.str();
    }
    friend ostream& operator<<(ostream& os, const DateTime& dt)
    {
        os << dt.asString();
        return os;
    }
    // comparison
    bool operator==(const DateTime& dt)
    {
        return Date::operator==(dt) && Time::operator==(dt);
    }
    bool operator<(const DateTime& dt)
    {
        return Date::operator<(dt) && Time::operator<(dt);
    }
};


#endif // DATETIME_H_INCLUDED
