#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

class DayTime
{
    private:
        // data members
        short hour, minute, second;
        bool overflow;
        static int objCounter;
    public:
        // constructor
        DayTime();  // default constructor
        DayTime(const DayTime&); // copy constructor
        DayTime(int, int, int);  // constructor
        bool setTime(int, int, int); // constructor helper
        // destructor
        ~DayTime();
        // getter
        short getHour(void)   const { return hour; }
        short getMinute(void) const { return minute; }
        short getSecond(void) const { return second; }
        static int getObjCounter(void) { return objCounter; }
        // setter
        void setHour(int h)   { if(h>=0 && h<=24) hour   = (short)h; }
        void setMinute(int m) { if(m>=0 && m<=60) minute = (short)m; }
        void setSecond(int s) { if(s>=0 && s<=60) second = (short)s; }
        static void setObjCounter(int n) { if(n >= 0) objCounter = n; }
        // comparison
        int asSeconds(void) const;
        bool isLess(const DayTime&);
        bool isEqual(const DayTime&);
        // print
        void print(void) const;
        // methods to overload operators
        bool operator<(const DayTime&) const;
        DayTime& operator++(void);
};

#endif // DAYTIME_H_INCLUDED
