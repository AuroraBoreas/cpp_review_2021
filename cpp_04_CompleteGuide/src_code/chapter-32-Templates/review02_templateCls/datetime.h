#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include "date.h"
#include "time.h"
#include <string>
#include <sstream>
using std::ostream;
using std::string;
using std::stringstream;

class DateTime: public Date, public Time
{
public:
    // constructor
    DateTime()
    {
        Date();
        Time();
    }
    DateTime(unsigned int yr, unsigned int mo, unsigned int da,
             unsigned short hr, unsigned short mi, unsigned short se)
    : Date(yr, mo, da), Time(hr, mi, se){}

    void setDateTime(void)
    {
        Date::setDate();
        Time::setTime();
    }
    // destructor
    virtual ~DateTime(){}
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
        return (Date::operator==(dt) && Time::operator==(dt)); // upcasting
    }
    bool operator<(const DateTime& dt)
    {
        if(!Date::operator==(dt)) return (Date::operator<(dt)); // upcasting
        else                      return (Time::operator<(dt));
    }
};

#endif // DATETIME_H_INCLUDED
