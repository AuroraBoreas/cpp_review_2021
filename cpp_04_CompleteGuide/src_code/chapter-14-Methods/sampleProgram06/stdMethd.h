#ifndef STDMETHD_H_INCLUDED
#define STDMETHD_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CD
{
private:
    // data members
    string interpret, title;
    long seconds;
public:
    // constructor
    CD(const string& i = "",
       const string& t = "",
       long s          = 0L)
    {
        interpret = i; title = t; seconds = s;
    }
    ~CD() {}

    // accessing private data members
    const string& getInterpret() const { return interpret; }
    const string& getTitle() const { return title; }
    long getSeconds() const { return seconds; }
    // no setter methods for now
};

#endif // STDMETHD_H_INCLUDED
