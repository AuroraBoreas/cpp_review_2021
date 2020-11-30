#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class DateTime
{
private:
    short hour, minute, second;
public:
    // constructor
    DateTime(); // default
    DateTime(int h, int m, int s); // parameterized
    bool setDateTime(int hour, int minute, int second); // assistant
    void setDateTime(void); // set to current datetime
    // destructor
    virtual ~DateTime() {}
    // getter
    short getHour(void)   const { return hour; }
    short getMinute(void) const { return minute; }
    short getSecond(void) const { return second; }
    // setter
    void setHour(int h)   { if(h>=0 && h<24) hour = h; }
    void setMinute(int m) { if(m>=0 && m<60) minute = m; }
    void setSecond(int s) { if(s>=0 && s<60) second = s; }
    // comparison
    int asSeconds(void) const;
    bool operator==(const DateTime& d);
    bool operator<(const DateTime& d);
    // repr
    string asString(void) const;
    virtual void display(void) const
    {
        cout << this->asString() << endl;
    }
};

#endif // DATETIME_H_INCLUDED
