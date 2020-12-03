#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
    short hour, minute, second;
public:
    // constructor
    Time();
    Time(int, int, int);
    bool setTime(int, int, int);
    void setTime(void);
    // destructor
    virtual ~Time() {}
    // getter
    short getHour(void)   const { return hour; }
    short getMinute(void) const { return minute; }
    short getSecond(void) const { return second; }
    // setter
    void setHour(int h)   { if(h>=0 && h<=24) hour = h; }
    void setMinute(int m) { if(m>=0 && m<=60) minute = m; }
    void setSecond(int s) { if(s>=0 && s<=60) second = s; }
    // repr
    string asString(void) const;
    virtual void display(void) const
    {
        cout << asString() << endl;
    }
    // comparison
    int asSeconds(void) const;
    bool operator==(const Time& t);
    bool operator<(const Time& t);
};

#endif // TIME_H_INCLUDED
