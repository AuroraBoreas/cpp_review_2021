#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

// using SOLID principles to create class

class DayTime
{
    private:
        // data members
        short hour, minute, second;
    public:
        // constructors
        DayTime(); // default
        DayTime(int h, int m, int s); // parameterized
        DayTime(const DayTime& dt); // copy-constructor
        void setDayTime(void);    // set to current daytime
        bool setDayTime(int hour, int minute, int second); // assistant
        // destructor
        ~DayTime(void);
        // getter
        short getHour(void)   const { return hour; }
        short getMinute(void) const { return minute; }
        short getSecond(void) const { return second; }
        // setter
        void setHour(int h)   { if(h>=0 && h<=24) hour = h; }
        void setMinute(int m) { if(m>=0 && m<=60) minute = m; }
        void setSecond(int s) { if(s>=0 && s<=60) second = s; }
        // comparison
        int asSeconds(void) const;
        bool isEqual(const DayTime& dt) const;
        bool isLess(const DayTime& dt) const;
        // repr
        string& asString(void) const
        {
            static string ostr;
            stringstream ss;
            ss << setw(2) << setfill('0') << hour << ":"
               << setw(2) << setfill('0') << minute << ":"
               << setw(2) << setfill('0') << second;
            ss >> ostr;
            return ostr;
        }
        void print(void) const;
};

inline void DayTime::print(void) const
{
    cout << asString() << endl;
}

#endif // DAYTIME_H_INCLUDED
