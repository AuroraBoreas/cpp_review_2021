#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <ctime>
#include <iomanip>
#include <iostream>

class Time
{
    private:
        unsigned hour, minute, second;
    public:
        // constructor
        Time() { hour = minute = second = 0; }
        Time(const Time& t) = delete;
        Time& operator=(const Time& t) = delete;
        Time(unsigned ho, unsigned mi, unsigned se)
        {
            if(!setTime(ho, mi, se))
                hour = minute = second = 0;
            hour = ho; minute = mi; second = se;
        }
        bool setTime(unsigned h, unsigned m, unsigned s) const
        {
            if(   h>=0 && h<=24
               && m>=0 && m<=60
               && s>=0 && s<=60)
                return true;
            return false;
        }
        void setTime(void)
        {
            struct tm *tm;
            time_t sec; time(&sec);
            tm = std::localtime(&sec);

            hour   = (unsigned)tm->tm_hour;
            minute = (unsigned)tm->tm_min;
            second = (unsigned)tm->tm_sec;
        }
        // destructor
        virtual ~Time() {}
        // getter
        unsigned getHour(void)   const { return hour; }
        unsigned getMinute(void) const { return minute; }
        unsigned getSecond(void) const { return second; }
        // setter
        void setHour(unsigned h)   { hour = h; }
        void setMinute(unsigned m) { minute = m; }
        void setSecond(unsigned s) { second = s; }
        // repr
        friend std::ostream& operator<<(std::ostream& os, const Time& t)
        {
            os << std::setw(2) << std::setfill('0') << t.hour   << ":"
               << std::setw(2) << std::setfill('0') << t.minute << ":"
               << std::setw(2) << std::setfill('0') << t.second;
            return os;
        }
        // relational
        unsigned asSeconds(void) const
        { return (hour*60*60 + minute*60 + second); }
        bool operator==(const Time& t) const
        { return (this->asSeconds() == t.asSeconds()); }
        bool operator<(const Time& t) const
        { return (this->asSeconds() < t.asSeconds()); }
        bool operator<=(const Time& t) const
        { return (this->asSeconds() <= t.asSeconds()); }
        bool operator>(const Time& t) const
        { return (this->asSeconds() > t.asSeconds()); }
        bool operator>=(const Time& t) const
        { return (this->asSeconds() >= t.asSeconds()); }
};


#endif // TIME_H_INCLUDED
