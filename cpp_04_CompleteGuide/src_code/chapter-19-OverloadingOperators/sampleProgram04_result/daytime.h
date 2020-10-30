#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

#include <string>
#include <sstream>
using namespace std;

class DayTime
{
    private:
        short hour, minute, second;
        bool overflow;
    public:
        // constructor
        DayTime(int h=0, int m=0, int s=0)
        {
            if(!setTime(h, m, s))
                hour = minute = second = 0;
        }
        bool setTime(int hour, int minute, int second)
        {
            if(   hour   >= 0 && hour   <= 24
               && minute >= 0 && minute <= 60
               && second >= 0 && second <= 60)
            {
                this->hour   = (short)hour;
                this->minute = (short)minute;
                this->second = (short)second;
                return true;
            }
            else
                return false;
        }
        // getter
        short getHour(void)   const { return hour; }
        short getMinute(void) const { return minute; }
        short getSecond(void) const { return second; }
        // comparison
        int asSeconds(void) const { return (60*60*hour + 60*minute + second); }
        bool isEqual(const DayTime& z) const
        { return (this->asSeconds() == z.asSeconds()); }
        bool isLess(const DayTime& z) const
        { return (this->asSeconds() < z.asSeconds()); }
        // --- overload operators
        bool operator==(const DayTime& z) const
        { return (this->asSeconds() == z.asSeconds()); }
        bool operator<(const DayTime& z) const
        { return (this->asSeconds() < z.asSeconds()); }
        // display method
        string asString(void) const
        {
            stringstream ss;
            ss << hour << ":" << minute << ":" << second;
            return ss.str();
        }
        // print
        void print(ostream& os) const
        { os << asString() << endl; }
};

#endif // DAYTIME_H_INCLUDED
