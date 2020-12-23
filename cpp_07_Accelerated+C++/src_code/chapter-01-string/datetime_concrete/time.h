#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

class Time
{
    private:
        unsigned short hour, minute, second;
    public:
        // constructor
        Time(){ hour = minute = second = 0; }
        Time(unsigned short hour,
             unsigned short minute,
             unsigned short second)
        {
            if(!setTime(hour, minute, second))
                Time();
        }

        bool setTime(unsigned short hour,
                     unsigned short minute,
                     unsigned short second)
        {
            if(   hour   >=0 && hour   <= 24
               && minute >=0 && minute <= 60
               && second >=0 && second <= 60)
            {
                this->hour   = hour;
                this->minute = minute;
                this->second = second;
                return true;
            }
            return false;
        }

        void setTime(void)
        {
            struct tm* tm;
            time_t sec; std::time(&sec);
            tm = std::localtime(&sec);

            this->hour   = (unsigned short)tm->tm_hour;
            this->minute = (unsigned short)tm->tm_min;
            this->second = (unsigned short)tm->tm_sec;
        }
        // destructor
        virtual ~Time(){}
        // getter
        unsigned short getHour(void)   const { return hour; }
        unsigned short getMinute(void) const { return minute; }
        unsigned short getSecond(void) const { return second; }
        // setter
        void setHour(unsigned short h)   { hour = h; }
        void setMinute(unsigned short m) { minute = m; }
        void setSecond(unsigned short s) { second = s; }
        // repr

        std::string asString(void) const
        {
            std::stringstream ss;
            ss << std::setw(2) << std::setfill('0') << hour   << ":"
               << std::setw(2) << std::setfill('0') << minute << ":"
               << std::setw(2) << std::setfill('0') << second;
            return ss.str();
        }

        friend std::ostream& operator<<(std::ostream& os, const Time& t)
        {
            os << t.asString();
            return os;
        }
        // +
        // -
        // relational
        int asSeconds(void) const
        {
            return (hour*60*60 + minute*60 + second);
        }

        friend bool operator==(const Time& a, const Time& b)
        {
            return (a.asSeconds() == b.asSeconds());
        }
        friend bool operator<(const Time& a, const Time& b)
        {
            return (a.asSeconds() < b.asSeconds());
        }

};

#endif // TIME_H_INCLUDED
