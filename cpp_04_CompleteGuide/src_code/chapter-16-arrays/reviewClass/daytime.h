#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

class DayTime
{
    private:
        short hour, minute, second;
    public:
        // declaration of constructors
        DayTime();  // default
        DayTime(const DayTime&); // copy constructor
        DayTime(int, int, int); // specific constructor
        // declaration of destructor
        ~DayTime();
        bool setTime(int, int, int);
        // getter
        short getHour(void)   const { return hour; }
        short getMinute(void) const { return minute; }
        short getSecond(void) const { return second; }
        // setter
        void setHour(int h)     { if(h>=0 && h<=24) hour = h; }
        void setMinute(int m)   { if(m>-0 && m<=60) minute = m; }
        void setSecond(int s)   { if(s>=0 && s<=60) second = s; }
        // comparison
        int asSeconds(void) const;
        bool isEqual(const DayTime&) const;
        bool isLess(const DayTime&) const;
        // print
        void print(void) const;
};

#endif // DAYTIME_H_INCLUDED
