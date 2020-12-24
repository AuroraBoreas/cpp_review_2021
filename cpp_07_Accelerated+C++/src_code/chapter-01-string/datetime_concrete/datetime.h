#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include <string>
#include <sstream>
#include "time.h"
#include "date.h"

class DateTime: public Date, public Time
{
    public:
        // constructor
        DateTime(unsigned int ye, unsigned int mo, unsigned int da,
                 unsigned short h, unsigned short m, unsigned short s)
        : Date::Date(ye, mo, da), Time::Time(h, m, s){}

        void setDateTime(void)
        {
            Time::setTime();
            Date::setDate();
        }
        // destructor
        virtual ~DateTime(){}
        // getter
        // setter
        // repr
        std::string asString(void) const
        {
            std::stringstream ss;
            ss << Date::asString() << " " << Time::asString();
            return ss.str();
        }
        friend std::ostream& operator<<(std::ostream& os, const DateTime& dt)
        {
            os << dt.asString();
            return os;
        }
        // compare
        bool operator==(const DateTime& dt)
        {
            return (Date::operator==(dt) && Time::operator==(dt));
        }
        bool operator<(const DateTime& dt)
        {
            return (Date::operator<(dt) && Time::operator<(dt));
        }
};

#endif // DATETIME_H_INCLUDED
