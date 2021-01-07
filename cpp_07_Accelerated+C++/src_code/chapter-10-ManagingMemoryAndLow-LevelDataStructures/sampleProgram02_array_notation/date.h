#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <ctime>
#include <iostream>
#include <iomanip>

inline bool isLeapYear(unsigned year)
{
    return (year%4==0 && year%100!=0) || (year%400==0);
}

class Date
{
    private:
        unsigned ye, mo, da;
    public:
        // constructor
        Date()
        { ye = mo = da = 1; }
        Date(unsigned y, unsigned m, unsigned d)
        {
            if(!setDate(y, m, d))
            { ye = mo = da = 1; }
            else
            {
                ye = y;
                mo = m;
                da = d;
            }
        }
        bool setDate(unsigned y, unsigned m, unsigned d) const
        {
            if(m<1 || m>12) return false;
            if(d<1 || d>31) return false;
            switch(m)
            {
                case 2: if(isLeapYear(y))
                        {
                            if(d>29) return false;
                        }
                        else
                            if(d>28) return false;
                        break;
                case 4:
                case 6:
                case 9:
                case 11: if(d>30) return false;
            }

            return true;
        }
        void setDate(void)
        {
            struct tm * tm;
            time_t sec; time(&sec);
            tm = std::localtime(&sec);

            ye = (unsigned)tm->tm_year + 1900;
            mo = (unsigned)tm->tm_mon + 1;
            da = (unsigned)tm->tm_mday;
        }
        // destructor
        virtual ~Date(){}
        // repr
        friend std::ostream& operator<<(std::ostream& os, const Date& d)
        {
            os << std::setw(4) << std::setfill('0') << d.ye << "-"
               << std::setw(2) << std::setfill('0') << d.mo << "-"
               << std::setw(2) << std::setfill('0') << d.da;
            return os;
        }

        // relational
        bool operator==(const Date& d) const
        {
            return (this->ye == d.ye && this->mo == d.mo && this->da == d.da);
        }
        bool operator<(const Date& d) const
        {
            if(ye != d.ye)      return (ye<d.ye);
            else if(mo != d.mo) return (mo<d.mo);
            else                return (da<d.da);
        }
};

#endif // DATE_H_INCLUDED
