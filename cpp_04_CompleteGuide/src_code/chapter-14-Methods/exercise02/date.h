#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Date
{
    private:
        int month, day, year;
    public:
        // constructor, destructor
        Date()
        { month = day = 1; year = 2020; }
        Date(int month, int day, int year)
        {
            if(!setDate(month, day, year))
                month = day = 1; year = 2020;
        }
        ~Date() {}

        void setDate() { month = day = 1; year = 2020; }
        bool setDate(int mn, int da, int yr)
        {
            if(   month >= 1 && month <= 12
               && day   >= 1 && day   <= 31
               && year  >= 1 && year  <= 12)
            {
                this->month = month;
                this->day   = day;
                this->year  = year;
                return true;
            }
            else
                return false;
        }
        // getter
        int getMonth() const { return month; }
        int getDay()   const { return day; }
        int getYear()  const { return year; }
        // setter
        void setMonth(int mn) { month = mn; } // simple version w/o check
        void setDay(int da)   { day = da; }   // simple version w/o check
        void setYear(int yr)  { year = yr; }  // simple version w/o check

        int asDays() const    { return (month*30 + day + year*365); }

        bool isEqual(const Date& d) const { return (asDays() == d.asDays()); }
        bool isLess(const Date& d) const  { return (asDays() < d.asDays()); }

        const string& intToString(int) const;
        const string& asString() const;

        void print() const
        {
            cout << asString() << endl;
        }
};

inline const string& Date::intToString(int i) const
{
    static string str;
    stringstream iostream;
    iostream << std::setw(10) << i;
    iostream >> str;
    return str;
}

inline const string& Date::asString() const
{
    static string res;
    res = Date::intToString(month) + "-" + Date::intToString(day) + "-" + Date::intToString(year);
    return res;
}

#endif // DATE_H_INCLUDED
