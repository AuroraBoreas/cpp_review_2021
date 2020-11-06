#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Car
{
    private:
        long nr;
        string producer;
    public:
        // constructor
        Car(long n=0L, const string& prod="");
        // getter
        long getNr(void)            const { return nr; }
        const string& getProd(void) const { return producer; }
        // setter
        void setNr(long n)            { nr = n; }
        void setProd(const string& p) { producer = p; }
        // repr
        void display(void) const;
};

class PassCar: public Car
{
    private:
        string passCarType;
        bool sunRoof;
    public:
        // constructor
        PassCar(const string& tp, bool sr, int n=0, const string& hs="");
        // getter
        const string& getType(void) const { return passCarType; }
        bool getSunRoof(void)       const { return sunRoof; }
        // setter
        void setType(const string& s) { passCarType = s; }
        void setSunRoof(bool b)       { sunRoof = b; }
        // repr
        void display(void) const
        {
            Car::display(); // using :: to access base class method
            cout << "Type:          " << passCarType;
            cout << "\nSunRoof:     ";
            if(sunRoof)
                cout << "yes " << endl;
            else
                cout << "no  " << endl;
        }
};

// First version of the constructor of PassCar
inline PassCar::PassCar(const string& tp, bool sr, int n=0, const string& hs="")
{
    setNr(n); setProd(hs); // initialize members of base class

    passCarType = tp; // initialize members of derived class
    sunRoof = sr;
}

// Second version with base class initializer
inline PassCar::PassCar(const string& tp, bool sr, int n=0, const string& hs="")
: Car(n, hs)
{
    passCarType = tp;
    sunRoof = sr;
}

// Third version
inline PassCar::PassCar(const string& tp, bool sr, int n=0, const string& hs="")
: Car(n, hs), passCarType(tp), sunRoof(sr)
{
    // ...
}

#endif // CAR_H_INCLUDED
