#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

#include <iostream>

class DayTime
{
    private:
        short hour, minute, second;
    public:
        // constructor
        DayTime(int h = 0, int m = 0, int s = 0)
        {
            if(!setTime(h, m, s))
                hour = h; minute = m; second = s;
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
        // destructor
        ~DayTime() {}
        // getter
        short getHour()   const { return hour; }
        short getMinute() const { return minute; }
        short getSecond() const { return second; }
        // setter
        void setHour(int hour)     { this->hour = (short)hour; }
        void setMinute(int minute) { this->minute = (short)minute; }
        void setSecond(int second) { this->second = (short)second; }
        // print
        void print() const
        {
            std::cout << hour << ":" << minute << ":" << second << std::endl;
        }
};

#endif // DAYTIME_H_INCLUDED
