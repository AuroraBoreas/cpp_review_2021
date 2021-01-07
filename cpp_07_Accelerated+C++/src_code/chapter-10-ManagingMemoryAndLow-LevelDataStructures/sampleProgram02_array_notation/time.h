#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <ctime>
#include <iostream>
#include <iomanip>

class Time
{
    private:
        short hour, minute, second;
    public:
        // constructor
        Time(){ hour = minute = second = 0; }
        Time(short ho, short mi, short se)
        {
            if(!setTime(ho, mi, se))
                hour = minute = second = 0;
            hour   = ho;
            minute = mi;
            second = se;
        }
        bool setTime(short h, short m, short s) const
        {
            if(   h>=0 && h<=24
               && m>=0 && m<=60
               && s>=0 && s<=60)
            {
                return true;
            }
            return false;
        }
        void setTime(void)
        {
            struct tm *tm;
            time_t sec; time(&sec);
            tm = std::localtime(&sec);

            hour   = (short)tm->tm_hour;
            minute = (short)tm->tm_min;
            second = (short)tm->tm_sec;
        }
        // destructor
        virtual ~Time(){};
        // getter
        // setter
        // repr
        friend std::ostream& operator<<(std::ostream& os, const Time& t)
        {
            os << std::setw(2) << std::setfill('0') << t.hour   << ":"
               << std::setw(2) << std::setfill('0') << t.minute << ":"
               << std::setw(2) << std::setfill('0') << t.second;
            return os;
        }
        // relational
        short asSeconds(void) const
        {
            return (hour*60*60 + minute*60 + second);
        }
        bool operator==(const Time& t) const
        {
            return (this->asSeconds() == t.asSeconds());
        }
        bool operator<(const Time& t) const
        {
            return (this->asSeconds() < t.asSeconds());
        }
};


#endif // TIME_H_INCLUDED
