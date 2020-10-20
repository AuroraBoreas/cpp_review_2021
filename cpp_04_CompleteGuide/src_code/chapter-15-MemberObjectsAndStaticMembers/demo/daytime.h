#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

#include <iostream>
#include <sstream>
//using namespace std;

class DayTime
{
private:
    short hour, minute, second;
public:
    // constructors
    DayTime()
    { hour = minute = second = 0; } // default constructor
    DayTime(int h, int m, int s) // specific constructor
    {
        if(!setTime(h, m, s))
            hour = minute = second = 0;
    }
    bool setTime(int, int, int);
    // destructor
    ~DayTime(){};
    // getter
    short getHour()   const { return hour; }
    short getMinute() const { return minute; }
    short getSecond() const { return second; }
    // setter
    void setHour(int h)   { if(h >= 0 && h <= 24) hour = h; }
    void setMinute(int m) { if(m >= 0 && m <= 60) minute = m; }
    void setSecond(int s) { if(s >= 0 && s <= 60) second = s; }
    // comparison
    int asSeconds(void) const;
    bool isEqual(const DayTime&) const;
    bool isLess(const DayTime&) const;
    // print
    void print(void) const;
};

inline bool DayTime::setTime(int h, int m, int s)
{
    if(   h >= 0 && h <= 24
       && m >= 0 && m <= 60
       && s >= 0 && s <= 60)
    {
        this->hour = (short)h; this->minute = (short)m; this->second = (short)s;
        return true;
    }
    else
        return false;
}

inline int DayTime::asSeconds() const
{
    return (60*60*hour + 60*minute + second);
}

inline bool DayTime::isEqual(const DayTime& z) const
{
    return (this->asSeconds() == z.asSeconds());
}

inline bool DayTime::isLess(const DayTime& z) const
{
    return (this->asSeconds() < z.asSeconds());
}

inline void DayTime::print() const
{
    // convert int to string using builtin module stringstream
    std::string str;
    std::stringstream my_iostream;
    my_iostream << hour << ":" << minute << ":" << second;
    my_iostream >> str;
    std::cout << str << std::endl;
    // std::cout << hour << ":" << minute << ":" << second << std::endl;
}
#endif // DAYTIME_H_INCLUDED
