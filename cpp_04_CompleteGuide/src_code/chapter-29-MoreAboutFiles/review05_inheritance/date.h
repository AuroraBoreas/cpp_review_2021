#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <iostream>
using std::ostream;
using std::string;

class Date
{
private:
    short year, month, day;
public:
    // constructor
    Date();
    Date(int, int, int);
    void setDate(void); // set to the current date
    bool setDate(int, int, int);
    // destructor
    virtual ~Date() {}
    // getter
    short getYear(void)  const { return year; }
    short getMonth(void) const { return month; }
    short getDay(void)   const { return day; }
    // setter
    void setYear(int y)  { year = y; }
    void setMonth(int m) { month = m; }
    void setDay(int d)   { day = d; }
    // repr
    string asString(void) const;
    virtual void display(void) const
    {
        //...
    }
    friend ostream& operator<<(ostream& os, const Date& d)
    {
        os << d.asString() << std::endl;
        return os;
    }
    // comparison
    bool operator==(const Date& d);
    bool operator<(const Date& d);
};

#endif // DATE_H_INCLUDED
