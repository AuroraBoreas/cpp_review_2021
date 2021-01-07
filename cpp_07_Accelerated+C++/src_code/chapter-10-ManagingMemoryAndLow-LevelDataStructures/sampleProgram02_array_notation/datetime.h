#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include "date.h"
#include "time.h"

class DateTime: public Date, public Time
{
    public:
        // constructor
        DateTime(unsigned y, unsigned m, unsigned d,
                 short ho, short mi, short se)
        : Date(y, m, d), Time(ho, mi, se){}
        bool setDateTime(unsigned y, unsigned m, unsigned d,
                         short ho, short mi, short se) const
        {
            return (Date::setDate(y, m, d) && Time::setTime(ho, mi, se));
        }
        void setDateTime(void)
        {
            Date::setDate();
            Time::setTime();
        }
        // destructor
        ~DateTime(){}
        // repr
        friend std::ostream& operator<<(std::ostream& os, const DateTime& dt)
        {
            os << Date(dt) << " " << Time(dt);  // upcasting
            return os;
        }
        // relational
        bool operator==(const DateTime& dt)
        { return (Date::operator==(dt) && Time::operator==(dt)); }

        bool operator<(const DateTime& dt)
        { return (Date::operator<(dt) && Time::operator<(dt)); }
};

#endif // DATETIME_H_INCLUDED
