#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include "daytime.h"
DayTime& currentTime(void);

class Result
{
    private: // data members
        double val;
        DayTime time;
    public: // methods
        // constructors
        Result();
        Result(double w, const DayTime& z = currentTime());
        Result(double w, int hr, int min, int sec);
        // destructor
        ~Result() {};
        // getter
        double getVal() const          { return val; }
        const DayTime& getTime() const { return time; }
        // setter
        void setVal(double w)          { val = w; }
        void setTime(const DayTime& z) { time = z; }
        // others
        bool setTime(int hr, int min, int sec)
        { return time.setTime(hr, min, sec); }
        // print
        void print(void) const;
};


#endif // RESULT_H_INCLUDED
