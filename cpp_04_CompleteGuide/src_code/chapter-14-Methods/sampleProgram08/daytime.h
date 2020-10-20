#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

#include <iostream>
#include <iomanip>

class DayTime
{
    private:
        short hour, minute, second;
        bool overflow; // meaningless?
    public:
        DayTime(int h = 0, int m = 0, int s = 0)
        {
            if(!setTime(h, m, s))
                hour = minute = second = 0;
        }

        bool setTime(int hour,
                     int minute,
                     int second)
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
        ~DayTime(){}

        // accessing private data members
        // getter
        short getHour(void)   const { return hour; }
        short getMinute(void) const { return minute; }
        short getSecond(void) const { return second; }
        // setter
        void setHour(int hour)     { this->hour = (short)hour; }
        void setMinute(int minute) { this->minute = (short)minute; }
        void setSecond(int second) { this->second = (short)second; }
        // other methods
        int totalSeconds()
        { return (60*60*hour + 60*minute + second); }

        bool isLess(DayTime& t)
        {
            return this->totalSeconds() < t.totalSeconds();
        }
        void display(void) const;
};

inline void DayTime::display() const
{
    std::cout << std::setw(2) << std::setfill('0');
    std::cout << DayTime::hour << ":" << DayTime::minute << ":" << DayTime::second << std::endl;
}

#endif // DAYTIME_H_INCLUDED
