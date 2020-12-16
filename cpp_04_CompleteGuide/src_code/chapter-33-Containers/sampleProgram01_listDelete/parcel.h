#ifndef PARCEL_H_INCLUDED
#define PARCEL_H_INCLUDED

#include <string>
#include <iostream>
using std::string;
using std::ostream&;

class Parcel
{
private:
    unsigned int prio;
    string       info;
public:
    Parcel(unsigned int p, const string& s)
    : prio(p), info(s){}
    friend bool operator<(const Parcel& x, const Parcel& y)
    {
        return (x.prio < y.prio);
    }
    friend ostream& operator<<(ostream& os, const Parcel& x)
    {
        os << x.prio << " " << x.info;
        return os;
    }
};

#endif // PARCEL_H_INCLUDED
