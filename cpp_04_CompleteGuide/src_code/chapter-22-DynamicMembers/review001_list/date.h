#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
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
        // constructors
        Date(int ye, int mo, int da) // parameterized
        {
            if(!setDate(ye, mo, da))
                Date();
        }
        // assistant
        bool setDate(int year, int month, int day)
        {
            if(month < 1 || month > 12) return false;
            if(day < 1 || day > 31)     return false;
            switch(month)
            {
                case 2: if(isLeapYear(year))
                        {
                            if(day > 29) return false;
                        }
                        else
                            if(day > 28) return false;
                        break;
                case 4:
                case 6:
                case 9:
                case 11: if(day > 30) return false;
            }
            this->year  = (short)year;
            this->month = (short)month;
            this->day   = (short)day;
            return true;
        }
        // method member
        void setDate()
        {
            // current date
            struct tm *tm;
            time_t sec; time(&sec);
            tm = localtime(&sec);

            year  = tm->tm_year + 1900;
            month = tm->tm_mon + 1;
            day   = tm->tm_mday;
        }

        // getter
        short getYear(void)  const { return year; }
        short getMonth(void) const { return month; }
        short getDay(void)   const { return day; }
        // setter
        void setYear(int y)  { year = y; }
        void setMonth(int m) { month = m; }
        void setDay(int d)   { day = d; }
        // comparison
        friend bool operator<(const Date& d1, const Date& d2)
        {
            if(d1.year != d2.year)          return d1.year < d2.year;
            else if(d1.month != d2.month)   return d1.month < d2.month;
            else                            return d1.day < d2.day;
        }

        friend bool operator==(const Date& d1, const Date& d2)
        { return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day); }
        // repr
        string asString(void) const
        {
            stringstream ss;
            ss << setw(4) << setfill('0') << year << '-';
            ss << setw(2) << setfill('0') << month << '-';
            ss << setw(2) << setfill('0') << day;
            return ss.str();
        }
        friend ostream& operator<<(ostream& os, const Date& d)
        { os << d.asString(); return os; }
};

#endif // DATE_H_INCLUDED
