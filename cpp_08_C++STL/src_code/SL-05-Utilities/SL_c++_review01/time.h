#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <ctime>
#include <iostream>
#include <iomanip>

class Time
{
private:
    unsigned short hour, minute, second;
public:
    // constructor
    Time() { hour = minute = second = 0; }
    explicit Time(unsigned short ho,
                  unsigned short mi,
                  unsigned short se)
    : hour(ho), minute(mi), second(se){}
    ~Time(){}                       // destructor
    // overload
    void setTime(void)
    {
        struct tm *tm;
        time_t sec; std::time(&sec);
        tm = std::localtime(&sec);

        hour   = static_cast<unsigned short>(tm->tm_hour);
        minute = static_cast<unsigned short>(tm->tm_min);
        second = static_cast<unsigned short>(tm->tm_sec);
    }
    // getter
    unsigned short getHour(void)   const { return hour; }
    unsigned short getMinute(void) const { return minute; }
    unsigned short getSecond(void) const { return second; }
    // setter
    void setHour(unsigned short h)   { hour = h; }
    void setMinute(unsigned short m) { minute = m; }
    void setSecond(unsigned short s) { second = s; }
    // repr
    friend std::ostream& operator<<(std::ostream& os, const Time& t)
    {
        os << std::setw(2) << std::setfill('0') << t.hour   << ":"
           << std::setw(2) << std::setfill('0') << t.minute << ":"
           << std::setw(2) << std::setfill('0') << t.second;

        return os;
    }
    // comparison
    unsigned asSeconds(void) const
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
