#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>
using std::stringstream;
using std::string;
using std::ostream;

class Time
{
private:
    unsigned short hour, minute, second;
public:
    // constructor
    Time()
    {
        hour = minute = second = 0;
    }
    Time(unsigned short hour,
         unsigned short minute,
         unsigned short second)
    {
        if(!setTime(hour, minute, second))
            Time();
        this->hour   = hour;
        this->minute = minute;
        this->second = second;
    }
    bool setTime(unsigned short h,
                 unsigned short m,
                 unsigned short s)
    {
        if(   h >= 0 && h <= 24
           && m >= 0 && m <= 60
           && s >= 0 && s <= 60)
        {
            hour   = h;
            minute = m;
            second = s;
            return true;
        }
        return false;
    }
    void setTime(void)
    {
        struct tm *tm;
        time_t sec; std::time(&sec);
        tm = std::localtime(&sec);

        hour   = (unsigned short)tm->tm_hour;
        minute = (unsigned short)tm->tm_min;
        second = (unsigned short)tm->tm_sec;
    }
    // destructor
    virtual ~Time(){}
    // getter
    unsigned short getHour(void)   const { return hour; }
    unsigned short getMinute(void) const { return minute; }
    unsigned short getSecond(void) const { return second; }
    // setter
    void setHour(unsigned short h)   { hour = h; }
    void setMinute(unsigned short m) { minute = m; }
    void setSecond(unsigned short s) { second = s; }
    // repr
    string asString(void) const
    {
        stringstream ss;
        const char ch = '0';
        ss << std::setw(2) << std::setfill(ch) << hour   << ":"
           << std::setw(2) << std::setfill(ch) << minute << ":"
           << std::setw(2) << std::setfill(ch) << second;
        return ss.str();
    }
    friend ostream& operator<<(ostream& os, const Time& t)
    {
        os << t.asString();
        return os;
    }

    // comparison
    unsigned int asSeconds(void) const
    {
        return (hour*60*60 + minute*60 + second);
    }
    bool operator==(const Time& t)
    {
        return (asSeconds() == t.asSeconds());
    }
    bool operator<(const Time& t)
    {
        return (asSeconds() < t.asSeconds());
    }
    bool operator>(const Time& t)
    {
        return (asSeconds() > t.asSeconds());
    }
    bool operator!=(const Time& t)
    {
        return (asSeconds() != t.asSeconds());
    }
    bool operator<=(const Time& t)
    {
        return (asSeconds() <= t.asSeconds());
    }
    bool operator>=(const Time& t)
    {
        return (asSeconds() >= t.asSeconds());
    }
};

#endif // TIME_H_INCLUDED
