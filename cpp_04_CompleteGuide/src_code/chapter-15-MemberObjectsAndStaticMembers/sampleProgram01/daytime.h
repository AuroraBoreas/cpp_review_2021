#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

#include <iostream>

class DayTime
{
    private:
        // data members
        short hour, minute, second;

    public:
        // constructor, destructor
        DayTime(int hour = 0, int minute = 0, int second = 0)
        {
                if(!setTime(hour, minute, second))
                    hour = minute = second = 0;
        }
        ~DayTime() {}
        bool setTime(int, int, int);
        // getter
        short getHour()   const { return hour; }
        short getMinute() const { return minute; }
        short getSecond() const { return second; }
        // setter
        void setHour(int h)   { hour   = h; }
        void setMinute(int m) { minute = m; }
        void setSecond(int s) { second = s; }
        // print
        void print(void) const;
        // comparison
        int asSeconds(void) const;
        bool isEqual(const DayTime&) const;
        bool isLess(const DayTime&) const;
};

inline bool DayTime::setTime(int h, int m, int s)
{
    if(   h >= 0 && h <= 24
       && m >= 0 && m <= 60
       && s >= 0 && s <= 60)
    {
        hour   = (short)h;
        minute = (short)m;
        second = (short)s;
        return true;
    }
    else
        return false;
}

inline void DayTime::print() const
{
    std::cout << hour << ":" << minute << ":" << second << std::endl;
}

inline int DayTime::asSeconds() const
{
    return (60*60*hour + 60*minute + second);
}

inline bool DayTime::isEqual(const DayTime& dt) const
{
    return (this->asSeconds() == dt.asSeconds());
}

inline bool DayTime::isLess(const DayTime& dt) const
{
    return (this->asSeconds() < dt.asSeconds());
}

#endif // DAYTIME_H_INCLUDED
