#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

inline bool isLeapYear(int year)
{ return (year%4 == 0 && year%100 != 0) || year%400 == 0; }

class Date
{
    private:
        short year, month, day;
    public:
        // constructors
        Date() // default
        { year = month = day = 1; }

        Date(int ye, int mo, int da) // parameterized
        {
            if(!setDate(ye, mo, da))
                Date();
        }

        void setDate() // set to current date
        {
            struct tm *tm;
            time_t sec; time(&sec);
            tm = localtime(&sec);

            year  = (short)tm->tm_year + 1900;
            month = (short)tm->tm_mon + 1;
            day   = (short)tm->tm_mday;
        }
        bool setDate(int y, int m, int d) // assistant
        {
            if(m<1 || m>12)
            {
                cerr << "ValueError: m must be 1<= m <= 12" << endl;
                exit(1);
                return false;
            }
            if(d<1 || d>31)
            {
                cerr << "ValueError: d must be 1<= d <= 31" << endl;
                exit(1);
                return false;
            }
            switch(m)
            {
                case 2: if(isLeapYear(y))
                        {
                            if(d > 29) return false;
                        }
                        else
                            if(d > 28) return false;
                        break;
                case 4:
                case 6:
                case 9:
                case 11: if(d > 30) return false;
            }
            year  = (short)y;
            month = (short)m;
            day   = (short)d;
            return true;
        }
        // destructor, using auto
        // getter
        short getYear(void)  const { return year; }
        short getMonth(void) const { return month; }
        short getDay(void)   const { return day; }
        // setter
        void setYear(int y)  { year = y; }
        void setMonth(int m) { month = (m>=1 && m<=12)? m : 1; }
        void setDay(int d)   { day   = (d>=1 && d<=31)? d : 1; }
        // comparison, global op ol
        friend bool operator==(const Date& d1, const Date& d2)
        { return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day; }

        friend bool operator<(const Date& d1, const Date& d2)
        {
            if(d1.year != d2.year)        return d1.year < d2.year;
            else if(d1.month != d2.month) return d1.month < d2.month;
            else                          return d1.day < d2.day;
        }
        // repr
        string asString(void) const
        {
            stringstream ss;
            ss << setw(4) << setfill('0') << year << '-'
               << setw(2) << setfill('0') << month << '-'
               << setw(2) << setfill('0') << day;
            return ss.str();
        }
        friend ostream& operator<<(ostream& os, const Date& d)
        { os << d.asString(); return os; }
};

#endif // DATE_H_INCLUDED
