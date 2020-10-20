#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

class DayTime
{
private:
    short hour, minute, second;
public:
    // constructors
    DayTime();
    DayTime(int, int, int);
    bool setTime(int, int, int);
    // destructor
    ~DayTime() {}
    // getter
    short getHour()   const { return hour; }
    short getMinute() const { return minute; }
    short getSecond() const { return second; }
    // setter
    void setHour(int h)   { hour   = h; }
    void setMinute(int m) { minute = m; }
    void setSecond(int s) { second = s; }
    // comparison
    int asSeconds(void) const;
    bool isEqual(const DayTime&) const;
    bool isLess(const DayTime&) const;
    // print
    void print(void) const;
};

#endif // DAYTIME_H_INCLUDED
