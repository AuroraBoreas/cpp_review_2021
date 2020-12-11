#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::stringstream;
using std::ostream;

class Time
{
private:
    short hour, minute, second;
public:
    // constructor
    Time()
    {
        hour = minute = second = 0;
    }
    Time(int hour, int minute, int second)
    {
        if(!setTime(hour, minute, second))
            Time();
        this->hour   = (short)hour;
        this->minute = (short)minute;
        this->second = (short)second;
    }
    bool setTime(int h, int m, int s)
    {
        if(   (h<0 || h>24)
           && (m<0 || m>60)
           && (s<0 || s>60))
        {
            return false;
        }
        return true;
    }
    void setTime(void)
    {

        struct tm *tm;
        time_t sec; std::time(&sec);
        tm = std::localtime(&sec);

        hour   = (short)tm->tm_hour;
        minute = (short)tm->tm_min;
        second = (short)tm->tm_sec;
    }
    // destructor
    virtual ~Time(){}
    // getter
    short getHour(void)   const { return hour; }
    short getMinute(void) const { return minute; }
    short getSecond(void) const { return second; }
    // setter
    void setHour(int h)   { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSecond(int s) { second = s; }
    // repr
    string asString(void) const
    {
        stringstream ss;
        ss << std::setw(2) << std::setfill('0') << hour   << ":"
           << std::setw(2) << std::setfill('0') << minute << ":"
           << std::setw(2) << std::setfill('0') << second;
        return ss.str();
    }
    friend ostream& operator<<(ostream& os, const Time& t)
    {
        os << t.asString();
        return os;
    }
    // comparison
    int asSeconds(void) const
    {
        return (hour*60*60 + minute*60 + second);
    }
    bool operator==(const Time& t)
    {
        return (this->asSeconds() == t.asSeconds());
    }
    bool operator<(const Time& t)
    {
        return (this->asSeconds() < t.asSeconds());
    }
    bool operator>(const Time& t)
    {
        return (this->asSeconds() > t.asSeconds());
    }
    bool operator<=(const Time&  t)
    {
        return (this->asSeconds() <= t.asSeconds());
    }
    bool operator>=(const Time& t)
    {
        return (this->asSeconds() >= t.asSeconds());
    }
    bool operator!=(const Time& t)
    {
        return (this->asSeconds() != t.asSeconds());
    }

};

#endif // TIME_H_INCLUDED
