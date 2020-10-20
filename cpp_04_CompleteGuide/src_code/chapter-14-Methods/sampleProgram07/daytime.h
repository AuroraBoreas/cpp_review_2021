#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class DayTime
{
    private:
        // data members
        short hour, minute, second;
        bool overflow;

    public:
        // constructor, destructor
        DayTime(int h = 0,
                int m = 0,
                int s = 0)
        {
            // check if parameters legal
            overflow = false;
            if(!setTime(h, m, s))
                hour = minute = second = 0; // set parameters to 0 if illegal
            cout << "object addr: " << this << endl;
            //cout << "this addr:   " << &this << endl; // exception. why can't I get the address of this?
        }

        ~DayTime() {};

        bool setTime(int hour, int minute, int second)
        {
            if(   hour   >= 0 && hour   < 24
               && minute >= 0 && minute < 60
               && second >= 0 && second < 60)
            {
                // i see..
                // to demonstrate data members of class and data members of object
                // data members of class = local members of a method;
                this->hour   = (short)hour;
                this->minute = (short)minute;
                this->second = (short)second;
                return true;
            }
            else
                return false;
        }

        int getHour()   const { return hour; }
        int getMinute() const { return minute; }
        int getSecond() const { return second; }

        int asSeconds() const
        {
            return (60*60*hour + 60*minute + second);
        }

        bool isLess(DayTime t) const
        {
            return this->asSeconds() < t.asSeconds();
        }

        void repr(void) const;

        void swap(DayTime& t);
};

inline void DayTime::repr() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}

inline void DayTime::swap(DayTime& t)
{
    // using this in implementation out of class definition works ..
    // DayTime temp(t); t = *this; *this = temp;
    // or
    // this is the memory address of the current object
    // temp is also the address of the current object
    // or
    // Class_id* const this = &actObj;
    DayTime temp = t;
    t = *this;
    *this = temp; // is equivalent to  &actObj = temp;
}

#endif // DAYTIME_H_INCLUDED
